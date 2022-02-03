#include <any>
#include <cstddef>
#include <cstdio>
#include <forward_list>
#include <fstream>
#include <iostream>
#include <llvm/ADT/APInt.h>
#include <llvm/IR/Instruction.h>
#include <llvm/IR/Value.h>
#include <string>
#include <map>
#include <queue>
#include <set>
#include <system_error>
#include <typeinfo>
#include "support/Any.h"
#include "testLanguageLexer.h"
#include "testLanguageParser.h"
#include "testLanguageBaseListener.h"
#include "antlr4-runtime.h"
#include "tree/ParseTreeProperty.h"
#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"
#include "llvm/Support/Host.h"
#include "llvm/Target/TargetOptions.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/TargetRegistry.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Transforms/InstCombine/InstCombine.h"
#include "llvm/Transforms/Scalar.h"
#include "llvm/Transforms/Scalar/GVN.h"
#include "llvm/Transforms/Utils.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/FileSystem.h"

using namespace antlr4;
using namespace llvm;


class Scope {
    public:
        Value* value;
        Scope(BasicBlock* block, std::string name="") : name(name), deferBlock(nullptr), llvmBlock(block){ }
        std::string name;
        std::map<std::string, AllocaInst*>                      variables;
        std::map<std::string, Function*>                        functions;
        std::map<std::string, Type*>                            variableTypes;
        std::map<std::string, FunctionType*>                    functionTypes;
        std::map<StructType*, std::map<std::string, Value*>>    structMembers;
        BasicBlock*                                             deferBlock;
        BasicBlock*                                             llvmBlock;
};

class TreeShapeListener : public testLanguageBaseListener {
    private:
        std::forward_list<Scope> scopeList;
        std::vector<Value*>      *aux_vec;
        Function* program;
        AllocaInst* findVariable(const std::string &target){
            for(Scope &scope : scopeList){
                if(scope.variables.find(target)!=scope.variables.end()){
                    return scope.variables.find(target)->second;
                }
            }
            return nullptr;
        }
        Function* findFunction(const std::string &target){
            for(Scope &scope : scopeList){
                if(scope.functions.find(target)!=scope.functions.end()){
                    return scope.functions.find(target)->second;
                }
            }
            return nullptr;
        }
        Scope* findValueScope(const std::string &target){
            for(Scope &scope : scopeList){
                if(scope.variables.find(target)!=scope.variables.end()){
                    return &scope;
                }
            }
            return nullptr;
        }
        Scope* findFunctionScope(const std::string &target){
            for(Scope &scope : scopeList){
                if(scope.functions.find(target)!=scope.functions.end()){
                    return &scope;
                }
            }
            return nullptr;
        }
        Type* findVariableType(const std::string &target){
            for(Scope &scope : scopeList){
                if(scope.variableTypes.find(target)!=scope.variableTypes.end()){
                    return scope.variableTypes.find(target)->second;
                }
            }
            return nullptr;
        }
        FunctionType* findFunctionType(const std::string &target){
            for(Scope &scope : scopeList){
                if(scope.functionTypes.find(target)!=scope.functionTypes.end()){
                    return scope.functionTypes.find(target)->second;
                }
            }
            return nullptr;
        }
        std::map<std::string, Value*> *findStructMembers(StructType* type){
            for(Scope &scope : scopeList){
                if(scope.structMembers.find(type)!=scope.structMembers.end()){
                    return &(scope.structMembers.find(type)->second);
                }
            }
            return nullptr;
        }
        AllocaInst* allocVariable(Type* type, const std::string name){
            return llvmBuilder->CreateAlloca(type, 0, name.c_str());
        }
            
    public:
        LLVMContext *llvmContext;
        IRBuilder<> *llvmBuilder;
        Module      *llvmModule;
        legacy::FunctionPassManager *llvmFPM;
        std::map<std::string, Value *> NamedValues;
        tree::ParseTreeProperty<Value*> values;
        TreeShapeListener(){
            llvmContext = new LLVMContext;
            llvmBuilder = new IRBuilder<>(*llvmContext);
            llvmModule  = new Module("my module", *llvmContext);
            aux_vec = new std::vector<Value*>;
            aux_vec->reserve(3);
            /*llvmFPM     = new legacy::FunctionPassManager(llvmModule);
            // Promote allocas to registers.
            llvmFPM->add(createPromoteMemoryToRegisterPass());
            // Do simple "peephole" optimizations and bit-twiddling optzns.
            llvmFPM->add(createInstructionCombiningPass());
            // Reassociate expressions.
            llvmFPM->add(createReassociatePass());
            // Eliminate Common SubExpressions.
            llvmFPM->add(createGVNPass());
            // Simplify the control flow graph (deleting unreachable blocks, etc).
            llvmFPM->add(createCFGSimplificationPass());
            // Promote allocas to registers.
            llvmFPM->add(createPromoteMemoryToRegisterPass());
            // Do simple "peephole" optimizations and bit-twiddling optzns.
            llvmFPM->add(createInstructionCombiningPass());
            // Reassociate expressions.
            llvmFPM->add(createReassociatePass());

            llvmFPM->doInitialization();*/
        }

        Type* identifyVariableType(testLanguageParser::Variable_typeContext *ctx){
            Type* type;
            if(!findVariableType(ctx->Type()->getText())){
                errs()<<ctx->getText()<<"\n";
                errs()<<ctx->Type()->getText()<<" is not a declared type.";
                return nullptr;
            } else if(ctx->Integer()){
                Type* subType = findVariableType(ctx->Type()->getText());
                type = FixedVectorType::get(subType, stoul(ctx->Integer()->getText()));
            }else type = findVariableType(ctx->Type()->getText());
            return type;
        }

        void enterProgram(testLanguageParser::ProgramContext *ctx) override{
            FunctionType* type = FunctionType::get(Type::getInt32Ty(*llvmContext), false);
            program = Function::Create(type, Function::ExternalLinkage, "main", llvmModule);
            BasicBlock* functionBlock = BasicBlock::Create(*llvmContext, "main_block", program);
            scopeList.push_front(Scope(functionBlock, "_global"));
            llvmBuilder->SetInsertPoint(functionBlock);
            FunctionType* printrType = FunctionType::get(Type::getInt32Ty(*llvmContext), Type::getFloatTy(*llvmContext), false);
            Function* pr = Function::Create(printrType, Function::ExternalLinkage, "printr", llvmModule);
            pr->args().begin()->setName("f");
            scopeList.front().functions["printr"] = pr; 
            FunctionType* printdType = FunctionType::get(Type::getInt32Ty(*llvmContext), Type::getInt32Ty(*llvmContext), false);
            Function* pd = Function::Create(printdType, Function::ExternalLinkage, "printd", llvmModule);
            pd->args().begin()->setName("n");
            scopeList.front().functions["printd"] = pd;
            scopeList.front().variableTypes["Int"] = Type::getInt32Ty(*llvmContext);
            scopeList.front().variableTypes["Float"] = Type::getFloatTy(*llvmContext);
            AllocaInst* returnVar = allocVariable(Type::getInt32Ty(*llvmContext), "returnValue");
            scopeList.front().variables["returnValue"] = returnVar;
            llvmBuilder->CreateStore(ConstantInt::get(*llvmContext, APInt(32, 0, true)), returnVar);
        }

        void exitProgram(testLanguageParser::ProgramContext *ctx) override{
            AllocaInst* returnVar = findVariable("returnValue");
            BasicBlock* scopeBlock   = scopeList.front().llvmBlock;
            if(scopeList.front().deferBlock){
                while(scopeList.front().deferBlock->begin()!=scopeList.front().deferBlock->end()){
                    auto defer = &*scopeList.front().deferBlock->begin();
                    defer->removeFromParent();
                    scopeBlock->getInstList().push_back(defer);
                }
                scopeList.front().deferBlock->eraseFromParent();
            }
            Value* returnValue = llvmBuilder->CreateLoad(Type::getInt32Ty(*llvmContext), returnVar, "returnValue");
            llvmBuilder->CreateRet(returnValue);
            scopeList.pop_front();
            verifyFunction(*program);
        }

        void enterDefer_statement(testLanguageParser::Defer_statementContext *ctx) override{
            if(!scopeList.front().deferBlock){
                scopeList.front().deferBlock = BasicBlock::Create(*llvmContext, "deferblk", llvmBuilder->GetInsertBlock()->getParent());
                llvmBuilder->SetInsertPoint(scopeList.front().deferBlock);
            } else{
                llvmBuilder->SetInsertPoint(scopeList.front().deferBlock->getFirstNonPHI());
            }
        }

        void exitDefer_statement(testLanguageParser::Defer_statementContext *ctx) override{
            llvmBuilder->SetInsertPoint(scopeList.front().llvmBlock);
        }


        void enterDeclaration(testLanguageParser::DeclarationContext *ctx) override{
            if(ctx->function_declaration()){
                auto dec = ctx->function_declaration();
                BasicBlock* afterBlock = llvmBuilder->GetInsertBlock();
                values.put(dec->scopeBlock(), afterBlock);
                if(!scopeList.front().name.length()){
                    errs()<<dec->getText()<<"\n";
                    errs()<<"Functions declarations can only happen at global scope or directly inside namespaces, the declaration for "<<dec->Id()->getText()<<" satisfies neither conditions.\n";
                    return;
                }
                if(findVariable(dec->Id()->getText()) || findFunction(dec->Id()->getText())){
                    errs()<<dec->getText()<<"\n";
                    errs()<<"Id "<<dec->Id()->getText()<<" was already declared.\n";
                    return;
                }
                FunctionType *functionType = translateFunctionType(dec->function_type());
                if(!functionType){
                    errs()<<dec->getText()<<"\n";
                    errs()<<"Failed to instantiate function type "<<dec->function_type()->getText()<<".\n";
                    return;
                }
                Function *function = Function::Create(functionType, Function::PrivateLinkage, dec->Id()->getText(), llvmModule);
                int index = 0;
                for(auto &arg : function->args()){
                    arg.setName(dec->function_type()->formal_parameter_list(0)->formal_parameter(index++)->Id()->getText());
                }
                scopeList.front().functions[dec->Id()->getText()] = function;
                values.put(dec, function);
            }
        }

        void exitDeclaration(testLanguageParser::DeclarationContext *ctx) override{
            if(ctx->id_declaration()){
                auto dec = ctx->id_declaration();
                std::vector<Value*> *exprValues = extractValuesFromExpressionList(dec->expression());
                if(!exprValues){
                    errs()<<ctx->getText()<<"\n";
                    errs()<<"Failed to get values for the assignments.\n";
                    return;
                }
                if(exprValues->size() && exprValues->size()>1 && dec->Id().size()!=exprValues->size()){ 
                    errs()<<dec->getText()<<"\n";
                    errs()<<"Different number of variables and values: "<<dec->Id().size()<<" vs " <<dec->expression().size()<<"\n";
                    return;
                }
                Type* type = identifyVariableType(dec->variable_type());
                if(!type){
                    errs()<<dec->getText()<<"\n";
                    errs()<<"Type " <<dec->variable_type()->getText() <<" was not defined.\n";
                    return;
                }
                int index = 0;
                for(auto& id: dec->Id()){
                    if(findVariable(id->getText())) {
                        errs()<<dec->getText()<<"\n";
                        errs()<<"Variable "<<id->getText()<<" was already defined.\n";
                        ++index;
                        continue;
                    } 
                    AllocaInst* var = allocVariable(type, id->getText());
                    scopeList.front().variables[id->getText()] = var;
                    if(exprValues->size()){
                        int internalIndex = 0;
                        if(exprValues->size()>1){
                            internalIndex = index; 
                        }
                        if((*exprValues)[internalIndex]->getType()==type){
                            llvmBuilder->CreateStore((*exprValues)[internalIndex], var);
                        } else{
                            std::cout<<"Type of value is "<<(*exprValues)[internalIndex]->getType()<<" while type of variable is "<<type->getTypeID()<<std::endl;
                            errs()<<dec->getText()<<"\n";
                            errs()<<"Conflicting types of variable "<<id->getText()<<" and its corresponding expression, "<<dec->expression(internalIndex)->getText()<<".\n";
                            ++index;
                            continue;
                        }
                        ++index;
                    }
                }
            } 
        }

        void exitFunction_call(testLanguageParser::Function_callContext *ctx) override{
            Function* function = llvmModule->getFunction(ctx->Id()->getText());
            if(!function){
                errs()<<ctx->getText()<<"\n";
                errs()<<"Function "<<ctx->Id()->getText()<<" hasn't been defined.\n";
                return;
            }
            std::vector<Value*> *args = extractValuesFromExpressionList(ctx->expression());
            if(!args){
                errs()<<ctx->getText()<<"\n";
                errs()<<"Couldn't get the values for the function call.\n";
                return;
            }
            if(args->size()!=function->getFunctionType()->getNumParams()){
                errs()<<ctx->getText()<<"\n";
                errs()<<"The function takes "<<function->getFunctionType()->getNumParams()<<" while you gave "<<args->size()<<".\n";
            }
            bool error = false;
            for(unsigned long i=0;i<args->size();++i){
                if((*args)[i]->getType()!=function->getFunctionType()->getParamType(i)){
                    errs()<<ctx->getText()<<"\n";
                    errs()<<"The value for parameter "<<i<<" was "<<(*args)[i]->getType()<<", should have been "<<function->getFunctionType()->getParamType(i)<<"\n";
                    error = true;
                }
            }
            if(error) return;
            values.put(ctx, llvmBuilder->CreateCall(function, *args, ctx->Id()->getText().substr(0, 3) + "call"));
        }

        bool translateFunctionType_helper(const std::vector<testLanguageParser::Formal_parameterContext*> parameters, std::vector<Type*> *types){
            int index = 0;
            for(auto &parameter : parameters){
                if(parameter->variable_type()){
                    if(findVariableType(parameter->variable_type()->getText())){
                        (*types)[index] = findVariableType(parameter->variable_type()->getText());
                    } else{
                        errs()<<"During a function type instantiation could not find type "<<parameter->variable_type()->getText()<<".\n";
                        return false;
                    }
                } else{
                    (*types)[index] = translateFunctionType(parameter->function_type());
                    if(!(*types)[index]) return false;
                }
                ++index;
            }
            return true;
        }

        FunctionType* translateFunctionType(testLanguageParser::Function_typeContext *ctx){
            if(ctx->Type()){
                return findFunctionType(ctx->Type()->getText());
            }
            std::vector<Type*> ins (ctx->formal_parameter_list(0)->formal_parameter().size());
            std::vector<Type*> outs(ctx->formal_parameter_list(1)->formal_parameter().size());
            if(!translateFunctionType_helper(ctx->formal_parameter_list(0)->formal_parameter(), &ins)) return nullptr;
            if(!translateFunctionType_helper(ctx->formal_parameter_list(1)->formal_parameter(), &outs)) return nullptr;
            if(outs.size()==0){
                if(ins.size()==0){
                    return FunctionType::get(Type::getVoidTy(*llvmContext), false);
                } else{
                    return FunctionType::get(Type::getVoidTy(*llvmContext), ins, false);
                }
            } else if(outs.size()==1){
                if(ins.size()==0){
                    return FunctionType::get(outs[0], false);
                } else{
                    return FunctionType::get(outs[0], ins, false);
                }
            } else{
                if(ins.size()==0){
                    return FunctionType::get(StructType::get(*llvmContext, outs), false);
                } else{
                    return FunctionType::get(StructType::get(*llvmContext, outs), ins, false);
                }
            }
        }

        std::vector<Value*> *extractValuesFromExpressionList(const std::vector<testLanguageParser::ExpressionContext*> &expressions){
            //What this function return is a class variable that is meant to be reused between calls to avoid allocating and freeing memory, so we clear and reserve it here instead
            //of forcing the caller to do the accounting
            aux_vec->clear();
            aux_vec->reserve(expressions.size());
            for(auto &expression : expressions){
                Value* value = values.get(expression);
                if(!value){
                    errs()<<"Expression "<<expression->getText()<<" had no computable value.\n";
                    return nullptr;
                }
                if(value->getType()->isStructTy() && static_cast<StructType*>(value->getType())->isLiteral()){
                    std::vector<Value*> indexes(2);
                    indexes[0] =  ConstantInt::get(*llvmContext, APInt(32, 0));
                    StructType* type = static_cast<StructType*>(value->getType());
                    AllocaInst* ptr = allocVariable(type, "");
                    llvmBuilder->CreateStore(value, ptr);
                    int elementNumber = type->getNumElements();
                    for(int i=0;i<elementNumber;++i){
                        indexes[1] = ConstantInt::get(*llvmContext, APInt(32, i));
                        Value* gepIndex = llvmBuilder->CreateGEP(type, ptr, indexes);
                        aux_vec->push_back(llvmBuilder->CreateLoad(type->getElementType(i), gepIndex));
                    }
                } else aux_vec->push_back(value);
            }
            return aux_vec;
        }

        Type* translateType(testLanguageParser::Variable_type_declarationContext *ctx){
            auto types = ctx->variable_type();
            if(types.size()==1) return identifyVariableType(types[0]);
            std::vector<Type*> elementTypes;
            bool error = false;
            for(auto &type : types){
                Type* elementType = identifyVariableType(type);
                if(!elementType){
                    errs()<<"In instantiation of type "<<ctx->Type()<<", couldn't find subtype "<<type->getText()<<"\n";
                    error = true;
                    continue;
                }
                elementTypes.push_back(elementType);
            }
            if(error) return nullptr;
            return StructType::create(elementTypes, ctx->Type()->getText());
        }

        void exitVariable_type_declaration(testLanguageParser::Variable_type_declarationContext *ctx) override{
            if(findVariableType(ctx->Type()->getText())){
                errs()<<ctx->getText()<<"\n";
                errs()<<ctx->Type()->getText()<<" was already defined.\n";
                return;
            }
            Type* type = translateType(ctx);
            if(!type){
                errs()<<ctx->getText()<<"\n";
                errs()<<"Failed to instantiate type "<<ctx->Type()->getText()<<".\n";
                return;
            }
            scopeList.front().variableTypes[ctx->Type()->getText()] = type;
            if(type->isStructTy()){
                StructType* strType = static_cast<StructType*>(type);
                std::map<std::string, Value*> map;
                for(unsigned i=0;i<strType->getNumElements();++i){
                    map[ctx->Id(i)->getText()] = ConstantInt::get(*llvmContext, APInt(32, i, true));
                }
                scopeList.front().structMembers[strType] = std::move(map);
            }
        }

        void exitFunction_type_declaration(testLanguageParser::Function_type_declarationContext *ctx) override{
            if(findFunctionType(ctx->Type()->getText())){
                errs()<<ctx->getText()<<"\n";
                errs()<<ctx->Type()->getText()<<" was already defined.\n";
                return;
            }
            if(!(ctx->function_type()->formal_parameter_list(1)->formal_parameter().size())){
                errs()<<ctx->getText()<<"\n";
                errs()<<"Function return arguments cannot be empty, you gave "<<ctx->getText()<<"\n";
                return;
            }
            FunctionType* type = translateFunctionType(ctx->function_type());
            if(!type) return;
            scopeList.front().functionTypes[ctx->Type()->getText()] = type;
        }

        void exitAssignment(testLanguageParser::AssignmentContext *ctx) override{
            std::vector<Value*> *exprValues = extractValuesFromExpressionList(ctx->expression());
            if(!exprValues){
                errs()<<ctx->getText()<<"\n";
                errs()<<"Failed to get values for the assignments.\n";
                return;
            }
            if(ctx->Id().size()){
                if(exprValues->size()!=1 && exprValues->size()!=ctx->Id().size()){
                    errs()<<ctx->getText()<<"\n";
                    errs()<<"You can either assign a single value to all variables, or one to each, you gave "<<ctx->expression().size()<<" values and "<<ctx->Id().size()<<" variables.\n";
                    return;
                }
                int index = 0;
                for(auto& id: ctx->Id()){
                    AllocaInst* var = findVariable(id->getText());
                    if(!var){
                        errs()<<ctx->getText()<<"\n";
                        errs()<<"Variable "<<id->getText()<<" was not defined.\n";
                        continue;
                    }
                    int internalIndex = 0;
                    if(exprValues->size()>1){
                        internalIndex = index;
                    }
                    if((*exprValues)[internalIndex]->getType()!=var->getType()->getPointerElementType()){
                        errs()<<ctx->getText()<<"\n";
                        errs()<<"Couldn't assign to "<<id->getText()<<" because its corrisponding expression, "<<ctx->expression(internalIndex)->getText()<<" had a different type: "<<(*exprValues)[internalIndex]->getType()<<" vs "<<var->getType()->getPointerElementType()<<".\n";
                        ++index;
                        continue;
                    } 
                    llvmBuilder-> CreateStore((*exprValues)[internalIndex], var);       
                    ++index;
                }
            } else{
                if(exprValues->size()!=1 && exprValues->size()!=ctx->member_access().size()){
                    errs()<<ctx->getText()<<"\n";
                    errs()<<"You can either assign a single value to all variables, or one to each, you gave "<<ctx->expression().size()<<" values and "<<ctx->member_access().size()<<" variables.\n";
                    return;
                }
                int index = 0;
                for(auto& member : ctx->member_access()){
                    AllocaInst* var = findVariable(member->Id(0)->getText());
                    if(!var){
                        errs()<<ctx->getText()<<"\n";
                        errs()<<member->Id(0)->getText()<<" was not defined.\n";
                        index++;
                        continue;
                    }
                    int internalIndex = 0;
                    if(exprValues->size()>1){
                        internalIndex = index;
                    }
                    if(
                        var->getType()->getPointerElementType()->isStructTy() && !static_cast<StructType*>(var->getType()->getPointerElementType())->isLiteral())
                        {
                        StructType* type = static_cast<StructType*>(findVariableType(std::string(var->getType()->getPointerElementType()->getStructName())));
                        std::map<std::string, Value*> *map = findStructMembers(type);
                        if(!map){
                            errs()<<ctx->getText()<<"\n";
                            errs()<<member->Id(0)->getText()<<" was of a defined type, but the definition of its members couldn't be found, this should NOT happen.\n";
                            index++;
                            continue;
                        }
                        if(map->find(member->Id(1)->getText())!=map->end()){
                            std::vector<Value*> indexes(2);
                            indexes[0] = ConstantInt::get(*llvmContext, APInt(32, 0));
                            indexes[1] = map->find(member->Id(1)->getText())->second;
                            if((*exprValues)[internalIndex]->getType()!=type->getTypeAtIndex(indexes[1])){
                                errs()<<ctx->getText()<<"\n";
                                errs()<<"Couldn't assign to "<<member->getText()<<" because its corrisponding expression, "<<ctx->expression(internalIndex)->getText()<<" had a different type: "<<(*exprValues)[internalIndex]->getType()<<" vs "<<type->getTypeAtIndex(indexes[1])<<".\n";
                                ++index;
                                continue;
                            } 
                            Value* gepIndex = llvmBuilder->CreateGEP(type, var, indexes);
                            llvmBuilder->CreateStore((*exprValues)[internalIndex], gepIndex);
                        } else{
                            errs()<<ctx->getText()<<"\n";
                            errs()<<"Type "<<type->getName()<<" had no field called "<<member->Id(1)->getText()<<".\n";
                            index++;
                            continue;
                        }
                    } else{
                        errs()<<ctx->getText()<<"\n";
                        errs()<<"Couldn't access members of "<<member->Id(0)->getText()<<" because it was not a composite type.\n";
                        index++;
                        continue;
                    }
                }
            }
        }

        void exitMember_access_expression(testLanguageParser::Member_access_expressionContext *ctx) override{
            AllocaInst* var = findVariable(ctx->member_access()->Id(0)->getText());
            if(!var){
                errs()<<ctx->getText()<<"\n";
                errs()<<ctx->member_access()->Id(0)->getText()<<" was not defined.\n";
                return;
            }
            if(
                var->getType()->getPointerElementType()->isStructTy() && !static_cast<StructType*>(var->getType()->getPointerElementType())->isLiteral())
                {
                StructType* type = static_cast<StructType*>(findVariableType(std::string(var->getType()->getPointerElementType()->getStructName())));
                std::map<std::string, Value*> *map = findStructMembers(type);
                if(!map){
                    errs()<<ctx->getText()<<"\n";
                    errs()<<ctx->member_access()->Id(0)->getText()<<" was of a defined type, but the definition of its members couldn't be found, this should NOT happen.\n";
                    return;
                }
                if(map->find(ctx->member_access()->Id(1)->getText())!=map->end()){
                    std::vector<Value*> indexes(2);
                    indexes[0] = ConstantInt::get(*llvmContext, APInt(32, 0));
                    indexes[1] = map->find(ctx->member_access()->Id(1)->getText())->second;
                    Value* gepIndex = llvmBuilder->CreateGEP(type, var, indexes);
                    values.put(ctx, llvmBuilder->CreateLoad(type->getTypeAtIndex(indexes[1]), gepIndex));
                } else{
                    errs()<<ctx->getText()<<"\n";
                    errs()<<"Type "<<type->getName()<<" had no field called "<<ctx->member_access()->Id(1)->getText()<<".\n";
                    return;
                }
            } else{
                errs()<<ctx->getText()<<"\n";
                errs()<<"Couldn't access members of "<<ctx->member_access()->Id(0)->getText()<<" because it was not a composite type.\n";
                return;
            }
        }

        void exitMultiply_expression(testLanguageParser::Multiply_expressionContext *ctx) override{
            if(values.get(ctx->expression(0))->getType()!=values.get(ctx->expression(1))->getType()){
                errs()<<ctx->getText()<<"\n";
                errs()<<"Can't mix different types without explicit cast: "<<values.get(ctx->expression(0))->getType()<<" vs "<<values.get(ctx->expression(1))->getType()<<".\n";
                return;
            }
            Value* L = values.get(ctx->expression(0));
            Value* R = values.get(ctx->expression(1));
            if(ctx->Star()){
                if(values.get(ctx->expression(0))->getType()->isFPOrFPVectorTy()){
                    values.put(ctx, llvmBuilder->CreateFMul(L, R, "fmultmp"));
                } else if(values.get(ctx->expression(0))->getType()->isIntOrIntVectorTy()){
                    values.put(ctx, llvmBuilder->CreateMul(L, R, "imultmp"));
                } else{
                    errs()<<ctx->getText();
                    errs()<<"We currently only support multiplying Floats or Ints, you gave "<<values.get(ctx->expression(0))->getType()<<" and "<<values.get(ctx->expression(1))->getType()<<".\n";
                    //TODO Do something for sums between other types
                }
            } else{
                if(values.get(ctx->expression(0))->getType()->isFPOrFPVectorTy()){
                    values.put(ctx, llvmBuilder->CreateFDiv(L, R, "fdivmp"));
                } else if(values.get(ctx->expression(0))->getType()->isIntOrIntVectorTy()){
                    values.put(ctx, llvmBuilder->CreateSDiv(L, R, "idivtmp"));
                } else{
                    errs()<<ctx->getText()<<"\n";
                    errs()<<"We currently only support dividing Floats or Ints, you gave "<<values.get(ctx->expression(0))->getType()<<" and "<<values.get(ctx->expression(1))->getType()<<".\n";
                    //TODO Do something for subtractions between other types
                }
            }
        }

        void exitSum_expression(testLanguageParser::Sum_expressionContext *ctx) override{
            if(values.get(ctx->expression(0))->getType()!=values.get(ctx->expression(1))->getType()){
                errs()<<ctx->getText()<<"\n";
                errs()<<"Can't mix different types without explicit cast: "<<values.get(ctx->expression(0))->getType()<<" vs "<<values.get(ctx->expression(1))->getType()<<".\n";
                return;
            }
            Value* L = values.get(ctx->expression(0));
            Value* R = values.get(ctx->expression(1));
            if(ctx->Plus()){
                if(L->getType()->isIntOrIntVectorTy()){
                    values.put(ctx, llvmBuilder->CreateAdd(L, R, "iaddtmp"));
                }else if(L->getType()->isFPOrFPVectorTy()){
                    values.put(ctx, llvmBuilder->CreateFAdd(L, R, "faddtmp"));
                } else{
                    errs()<<ctx->getText()<<"\n";
                    errs()<<"We currently only support adding Floats or Ints, you gave "<<values.get(ctx->expression(0))->getType()<<" and "<<values.get(ctx->expression(1))->getType()<<".\n";
                    //TODO Do something for sums between other types
                }
            } else{
                if(L->getType()->isFPOrFPVectorTy()){
                    values.put(ctx, llvmBuilder->CreateFSub(L, R, "fsubmp"));
                } else if(L->getType()->isIntOrIntVectorTy()){
                    values.put(ctx, llvmBuilder->CreateSub(L, R, "isubtmp"));
                } else{
                    errs()<<ctx->getText()<<"\n";
                    errs()<<"We currently only support subtractin Floats or Ints, you gave "<<values.get(ctx->expression(0))->getType()<<" and "<<values.get(ctx->expression(1))->getType()<<".\n";
                    //TODO Do something for subtractions between other types
                }
            }
        }

        void exitNegation_expression(testLanguageParser::Negation_expressionContext *ctx) override{
            Value* expr = values.get(ctx->expression());
            if(expr->getType()->isIntOrIntVectorTy()){
                values.put(ctx, llvmBuilder->CreateICmpEQ(expr, ConstantInt::get(expr->getType(), 0), "ineg"));
            } else if(expr->getType()->isFPOrFPVectorTy()){
                values.put(ctx, llvmBuilder->CreateFCmpUEQ(expr, ConstantFP::get(expr->getType(), 0.), "fneg"));
            }
        }

        void exitLogical_expression(testLanguageParser::Logical_expressionContext *ctx) override{
            if(values.get(ctx->expression(0))->getType()!=values.get(ctx->expression(1))->getType()){
                errs()<<ctx->getText()<<"\n";
                errs()<<"Can't mix different types without explicit cast: "<<values.get(ctx->expression(0))->getType()<<" vs "<<values.get(ctx->expression(1))->getType()<<".\n";
                return;
            }
            Value* L = values.get(ctx->expression(0));
            Value* R = values.get(ctx->expression(1));
            if(ctx->And()){
                if(L->getType()->isIntegerTy()){
                    Value* logicalL = llvmBuilder->CreateICmpNE(L, ConstantInt::get(L->getType(), 0), "ifL");
                    Value* logicalR = llvmBuilder->CreateICmpNE(R, ConstantInt::get(L->getType(), 0), "ifR");
                    values.put(ctx, llvmBuilder->CreateAnd(logicalL, logicalR, "LandR"));
                } else if(L->getType()->isFloatTy()){
                    Value* logicalL = llvmBuilder->CreateFCmpUNE(L, ConstantFP::get(L->getType(), 0.), "ffL");
                    Value* logicalR = llvmBuilder->CreateFCmpUNE(R, ConstantFP::get(L->getType(), 0.), "ffR");
                    values.put(ctx, llvmBuilder->CreateAnd(logicalL, logicalR, "LandR"));
                } else{
                    errs()<<"We currently only support logical operation of Floats or Ints, you gave "<<values.get(ctx->expression(0))->getType()<<" and "<<values.get(ctx->expression(1))->getType()<<".\n";
                }
            } else if(ctx->Or()){
                if(L->getType()->isIntegerTy()){
                    Value* logicalL = llvmBuilder->CreateICmpNE(L, ConstantInt::get(L->getType(), 0), "ifL");
                    Value* logicalR = llvmBuilder->CreateICmpNE(R, ConstantInt::get(L->getType(), 0), "ifR");
                    values.put(ctx, llvmBuilder->CreateOr(logicalL, logicalR, "LorR"));
                } else if(L->getType()->isFloatTy()){
                    Value* logicalL = llvmBuilder->CreateFCmpUNE(L, ConstantFP::get(L->getType(), 0.), "ffL");
                    Value* logicalR = llvmBuilder->CreateFCmpUNE(R, ConstantFP::get(L->getType(), 0.), "ffR");
                    values.put(ctx, llvmBuilder->CreateOr(logicalL, logicalR, "LorR"));
                } else{
                    errs()<<"We currently only support logical operation of Floats or Ints, you gave "<<values.get(ctx->expression(0))->getType()<<" and "<<values.get(ctx->expression(1))->getType()<<".\n";
                }
            } else if(ctx->Xor()){
                if(L->getType()->isIntegerTy()){
                    Value* logicalL = llvmBuilder->CreateICmpNE(L, ConstantInt::get(L->getType(), 0), "ifL");
                    Value* logicalR = llvmBuilder->CreateICmpNE(R, ConstantInt::get(L->getType(), 0), "ifR");
                    values.put(ctx, llvmBuilder->CreateXor(logicalL, logicalR, "LorR"));
                } else if(L->getType()->isFloatTy()){
                    Value* logicalL = llvmBuilder->CreateFCmpUNE(L, ConstantInt::get(*llvmContext, APInt(32, 0, true)), "ifL");
                    Value* logicalR = llvmBuilder->CreateFCmpUNE(R, ConstantInt::get(*llvmContext, APInt(32, 0, true)), "ifR");
                    values.put(ctx, llvmBuilder->CreateXor(logicalL, logicalR, "LorR"));
                } else{
                    errs()<<"We currently only support logical operation of Floats or Ints, you gave "<<values.get(ctx->expression(0))->getType()<<" and "<<values.get(ctx->expression(1))->getType()<<".\n";
                }
            }
        }

        void exitComparison_expression(testLanguageParser::Comparison_expressionContext *ctx) override{
            Value* L = values.get(ctx->expression(0));
            Value* R = values.get(ctx->expression(1));
            if(L->getType()!=R->getType()){
                errs()<<ctx->getText()<<"\n";
                errs()<<"Can't mix different types without explicit cast: "<<values.get(ctx->expression(0))->getType()<<" vs "<<values.get(ctx->expression(1))->getType()<<".\n";
                return;
            }
            if(ctx->LessOrEqual()){
                if(L->getType()->isIntOrIntVectorTy()){
                    values.put(ctx, llvmBuilder->CreateICmpSLE(L, R, "iLE"));
                } else if(L->getType()->isFPOrFPVectorTy()){
                    values.put(ctx, llvmBuilder->CreateFCmpOLE(L, R, "fLE"));
                } else{
                    errs()<<"We currently only support comparison operation of Floats or Ints, you gave "<<values.get(ctx->expression(0))->getType()<<" and "<<values.get(ctx->expression(1))->getType()<<".\n";
                }
            } else if(ctx->Less()){
                if(L->getType()->isIntOrIntVectorTy()){
                    values.put(ctx, llvmBuilder->CreateICmpSLT(L, R, "iLE"));
                } else if(L->getType()->isFPOrFPVectorTy()){
                    values.put(ctx, llvmBuilder->CreateFCmpOLT(L, R, "fLE"));
                } else{
                    errs()<<"We currently only support comparison operation of Floats or Ints, you gave "<<values.get(ctx->expression(0))->getType()<<" and "<<values.get(ctx->expression(1))->getType()<<".\n";
                }
            } else if(ctx->GreaterOrEqual()){
                if(L->getType()->isIntOrIntVectorTy()){
                    values.put(ctx, llvmBuilder->CreateICmpSGE(L, R, "iLE"));
                } else if(L->getType()->isFPOrFPVectorTy()){
                    values.put(ctx, llvmBuilder->CreateFCmpOGE(L, R, "fLE"));
                } else{
                    errs()<<"We currently only support comparison operation of Floats or Ints, you gave "<<values.get(ctx->expression(0))->getType()<<" and "<<values.get(ctx->expression(1))->getType()<<".\n";
                }
            } else if(ctx->Greater()){
                if(L->getType()->isIntOrIntVectorTy()){
                    values.put(ctx, llvmBuilder->CreateICmpSGT(L, R, "iLE"));
                } else if(L->getType()->isFPOrFPVectorTy()){
                    values.put(ctx, llvmBuilder->CreateFCmpOGT(L, R, "fLE"));
                } else{
                    errs()<<"We currently only support comparison operation of Floats or Ints, you gave "<<values.get(ctx->expression(0))->getType()<<" and "<<values.get(ctx->expression(1))->getType()<<".\n";
                }
            } else if(ctx->Equal()){
                if(L->getType()->isIntOrIntVectorTy()){
                    values.put(ctx, llvmBuilder->CreateICmpEQ(L, R, "iLE"));
                } else if(L->getType()->isFPOrFPVectorTy()){
                    values.put(ctx, llvmBuilder->CreateFCmpOEQ(L, R, "fLE"));
                } else{
                    errs()<<"We currently only support comparison operation of Floats or Ints, you gave "<<values.get(ctx->expression(0))->getType()<<" and "<<values.get(ctx->expression(1))->getType()<<".\n";
                }
            } else if(ctx->NotEqual()){
                if(L->getType()->isIntOrIntVectorTy()){
                    values.put(ctx, llvmBuilder->CreateICmpNE(L, R, "iLE"));
                } else if(L->getType()->isFPOrFPVectorTy()){
                    values.put(ctx, llvmBuilder->CreateFCmpONE(L, R, "fLE"));
                } else{
                    errs()<<"We currently only support comparison operation of Floats or Ints, you gave "<<values.get(ctx->expression(0))->getType()<<" and "<<values.get(ctx->expression(1))->getType()<<".\n";
                }
            }
        }

        void exitVariable_expression(testLanguageParser::Variable_expressionContext *ctx) override{
            AllocaInst* value = findVariable(ctx->Id()->getText());
            if(value){
                values.put(ctx, llvmBuilder->CreateLoad(value->getType()->getPointerElementType(), value, ctx->Id()->getText()));
            } else{
                errs()<<ctx->getText()<<"\n";
                errs()<<"Couldn't find variable "<<ctx->Id()->getText()<<".\n";
            }
        }

        void exitInvert_sign_expression(testLanguageParser::Invert_sign_expressionContext *ctx) override {
            Value* expr = values.get(ctx->expression());
            if(expr->getType()->isIntegerTy()){
                values.put(ctx, llvmBuilder->CreateSub(ConstantInt::get(expr->getType(), 0), expr, "invsig"));
            } else if(expr->getType()->isFPOrFPVectorTy()){
                values.put(ctx, llvmBuilder->CreateFNeg(expr, "finvsig"));
            } else{
                errs()<<ctx->getText()<<"\n";
                errs()<<"Currently we only allow changing sign of Floats or Ints.\n";
            }
        }

        void exitConstant_integer_expression(testLanguageParser::Constant_integer_expressionContext *ctx) override{
            values.put(ctx, ConstantInt::get(*llvmContext, APInt(32, stoll(ctx->Integer()->getText()), true)));
        }

        void exitConstant_float_expression(testLanguageParser::Constant_float_expressionContext *ctx) override{
            values.put(ctx, ConstantFP::get(*llvmContext, APFloat(stof(ctx->Float()->getText()))));
        }

        void exitInit_expression(testLanguageParser::Init_expressionContext *ctx) override{
            Type* type = identifyVariableType(ctx->variable_type());
            AllocaInst* value;
            if(!type) return;
            std::string name = "";
            if(type->isStructTy()){
                name = "tempstr";
                StructType* strType = static_cast<StructType*>(type);
                if(ctx->expression().size()!=strType->getNumElements()){
                    errs()<<ctx->getText()<<"\n";
                    errs()<<"Incorrect number of arguments to create variable, "<<strType->getNumElements()<<" expected, given "<<ctx->expression().size()<<".\n";
                    return;
                }
                int i = 0;
                value = allocVariable(strType, "tempstr");
                for(auto &expression : ctx->expression()){
                    if(values.get(expression)->getType()!=strType->getTypeAtIndex(i++)){
                        errs()<<ctx->getText()<<"\n";
                        errs()<<"Tried to initialize a "<<ctx->variable_type()->getText()<<" with an element of incorrect type, "<<expression->getText()<<".\n";
                        return;
                    }
                }
                i = 0;
                std::vector<Value*> indexes(2);
                indexes[0] = ConstantInt::get(*llvmContext, APInt(32, 0));
                for(auto &expression : ctx->expression()){
                    indexes[1] = ConstantInt::get(*llvmContext, APInt(32, i++));
                    Value* gepIndex = llvmBuilder->CreateGEP(strType, value, indexes);
                    llvmBuilder->CreateStore(values.get(expression), gepIndex); 
                }
            } else if(type->getTypeID()==Type::FixedVectorTyID){
                name = "tempvec";
                FixedVectorType* vecType = static_cast<FixedVectorType*>(type);
                Type* elType = vecType->getElementType();
                if(ctx->expression().size()!=vecType->getNumElements()){
                    errs()<<ctx->getText()<<"\n";
                    errs()<<"Incorrect number of arguments to create variable, "<<vecType->getNumElements()<<" expected, given "<<ctx->expression().size()<<".\n";
                    return;
                }
                for(auto &expression : ctx->expression()){
                    if(values.get(expression)->getType()!=elType){
                        errs()<<ctx->getText()<<"\n";
                        errs()<<"Tried to initialize a "<<ctx->variable_type()->getText()<<" with an element of incorrect type, "<<expression->getText()<<"\n";
                        return;
                    }
                }
                value = allocVariable(vecType, "tempvec");
                int i=0;
                for(auto &expression : ctx->expression()){
                    Value* index = ConstantInt::get(*llvmContext, APInt(32, i, true));
                    llvmBuilder->CreateInsertElement(value, values.get(expression), index, "tempvecins" + std::to_string(i)); 
                    ++i;
                }
            } else{
                errs()<<ctx->getText()<<"\n";
                errs()<<"Asked to build a fundamental type "<<ctx->variable_type()->getText()<<" with a composite expression.\n";
                return;
            }
            values.put(ctx, llvmBuilder->CreateLoad(value->getType()->getPointerElementType(), value, name));
        }

        void exitParenthesized_expression(testLanguageParser::Parenthesized_expressionContext *ctx) override{
            values.put(ctx, values.get(ctx->expression()));
        }

        void enterForStatement(testLanguageParser::ForStatementContext *ctx) override{
                Function* currentBlock      = llvmBuilder->GetInsertBlock()->getParent();
                BasicBlock* loopHeader = BasicBlock::Create(*llvmContext, "loophdr", currentBlock);
                llvmBuilder->CreateBr(loopHeader);
                llvmBuilder->SetInsertPoint(loopHeader);
        }

        void enterScopeBlock(testLanguageParser::ScopeBlockContext *ctx) override{
            if(ctx->parent && static_cast<antlr4::ParserRuleContext*>(ctx->parent)->getRuleIndex()==testLanguageParser::RuleFunction_declaration){
                testLanguageParser::Function_declarationContext* functx = static_cast<testLanguageParser::Function_declarationContext*>(ctx->parent);
                Function* function = static_cast<Function*>(values.get(functx));
                if(!function){
                    errs()<<functx->Func()->getText()<<" "<<functx->Id()->getText()<<" "<<functx->function_type()->getText()<<"\n";
                    errs()<<"The definition for function "<<functx->Id()->getText()<<" failed, can't attach its body.\n";
                    return;
                }
                BasicBlock *functionBlock = BasicBlock::Create(*llvmContext, functx->Id()->getText(), function);
                llvmBuilder->SetInsertPoint(functionBlock);
                scopeList.push_front(Scope(functionBlock, ""));
                int index = 0;
                if(function->arg_size()){
                    for(auto &arg : function->args()){
                        if(arg.getType()->isFunctionTy()){
                            //TODO
                        } else{
                            scopeList.front().variables[arg.getName().str()] = allocVariable(arg.getType(), functx->function_type()->formal_parameter_list(0)->formal_parameter(index++)->Id()->getText());
                        }
                    }
                }
                auto returns = functx->function_type()->formal_parameter_list(1)->formal_parameter();
                if(function->getReturnType()->isStructTy() && static_cast<StructType*>(function->getReturnType())->isLiteral()){
                    int index = 0;
                    auto return_types = static_cast<StructType*>(function->getReturnType());
                    for(auto &retType : return_types->elements()){
                        if(retType->isFunctionTy()){
                            scopeList.front().functions[returns[index]->getText()];
                            //TODO Find out how to generate a Value of a dynamically defined function type
                        } else{
                            scopeList.front().variables[returns[index]->Id()->getText()] = allocVariable(retType, returns[index]->Id()->getText());
                        }
                        index++;
                    }
                } else if(function->getReturnType()->isFunctionTy()){
                    //TODO
                } else {
                    scopeList.front().variables[returns[0]->Id()->getText()] = allocVariable(function->getReturnType(), returns[0]->Id()->getText());
                }
            } else if(ctx->parent && static_cast<antlr4::ParserRuleContext*>(ctx->parent)->getRuleIndex()==testLanguageParser::RuleForStatement){
                auto forStatement = static_cast<testLanguageParser::ForStatementContext*>(ctx->parent);
                Function* currentBlock      = llvmBuilder->GetInsertBlock()->getParent();
                AllocaInst* loopIndexVar;
                Value* indexedVar;
                AllocaInst* iteratorVar;
                std::string loopIndexVarName = "_loopindex";
                if(forStatement->forVariable(0)->Id()){
                    loopIndexVarName = forStatement->forVariable(0)->Id()->getText();
                }
                BasicBlock* loopBlock = BasicBlock::Create(*llvmContext, "loop", currentBlock);
                scopeList.push_front(Scope(loopBlock, ""));
                if(forStatement->expression()){
                    indexedVar = values.get(forStatement->expression());
                    if(!indexedVar){
                        errs()<<ctx->getText()<<"\n";
                        errs()<<"Loop variable "<<forStatement->expression()->getText()<<"had no value.\n";
                        llvmBuilder->SetInsertPoint(loopBlock);
                        return;
                    } else if(indexedVar->getType()->getTypeID()!=Type::FixedVectorTyID){
                        errs()<<ctx->getText()<<"\n";
                        errs()<<"Loop variable "<<forStatement->expression()->getText()<<" is of type "<<indexedVar->getType()->getPointerElementType()<<" while we only support fixed vectors.\n";
                        llvmBuilder->SetInsertPoint(loopBlock);
                        return;
                    }
                    std::string iteratorVarName = "_loopvar";
                    if(forStatement->forVariable(1)->Id()){
                        iteratorVarName = forStatement->forVariable(1)->Id()->getText();
                    }
                    iteratorVar = allocVariable(static_cast<FixedVectorType*>(indexedVar->getType())->getElementType(), iteratorVarName);
                    scopeList.front().variables[iteratorVarName] = iteratorVar;
                }
                loopIndexVar = allocVariable(Type::getInt32Ty(*llvmContext), loopIndexVarName.c_str());
                scopeList.front().variables[loopIndexVarName] = loopIndexVar;
                Value* initialValue;
                Value* endValue;    
                if(forStatement->Reverse()){
                    if(forStatement->range()){
                        initialValue    = values.get(forStatement->range()->expression(1));
                        endValue        = values.get(forStatement->range()->expression(0));
                        if(!initialValue->getType()->isIntegerTy() || !endValue->getType()->isIntegerTy()){
                            errs()<<forStatement->getText()<<"\n";
                            errs()<<"The extremes of the for loop range should be integers, they are "<<initialValue->getType()<<" and "<<endValue->getType()<<"\n";
                            llvmBuilder->SetInsertPoint(loopBlock);
                            return;
                        }
                    } else{
                        initialValue    = ConstantInt::get(*llvmContext, APInt(32, static_cast<FixedVectorType*>(indexedVar->getType())->getNumElements(), true));
                        endValue        = ConstantInt::get(*llvmContext, APInt(32, 0, true));
                    }
                } else{
                    if(forStatement->range()){
                        initialValue    = values.get(forStatement->range()->expression(0));
                        endValue        = values.get(forStatement->range()->expression(1));
                        if(!initialValue->getType()->isIntegerTy() || !endValue->getType()->isIntegerTy()){
                            errs()<<forStatement->getText()<<"\n";
                            errs()<<"The extremes of the for loop range should be integers, they are "<<initialValue->getType()<<" and "<<endValue->getType()<<"\n";
                            llvmBuilder->SetInsertPoint(loopBlock);
                            return;
                        }
                    } else{
                        initialValue    = ConstantInt::get(*llvmContext, APInt(32, 0, true));
                        endValue        = ConstantInt::get(*llvmContext, APInt(32, static_cast<FixedVectorType*>(indexedVar->getType())->getNumElements(), true));
                    }
                }
                values.put(forStatement->forVariable(0), endValue);
                llvmBuilder->CreateStore(initialValue, loopIndexVar);
                if(forStatement->forVariable(1)->Id() && forStatement->forVariable(1)->Id()){
                    Value* initialIteratorValue = llvmBuilder->CreateExtractElement(indexedVar, uint64_t(0), "iterinit");
                    llvmBuilder->CreateStore(initialIteratorValue, iteratorVar);
                }
                Value* stepValue;
                if(forStatement->byClause()){
                    stepValue = values.get(forStatement->byClause()->expression());
                } else{
                    stepValue = ConstantInt::get(*llvmContext, APInt(32, 1, true));
                }
                if(forStatement->In()){
                    values.put(forStatement->In(), stepValue);
                } else{
                    values.put(forStatement->range(), stepValue);
                }
                BasicBlock* afterBlock  = BasicBlock::Create(*llvmContext, "afterloop", currentBlock);
                values.put(ctx, afterBlock);
                Value* initialComparison;
                if(forStatement->Reverse()){
                    initialComparison = llvmBuilder->CreateICmpSLT(endValue, initialValue, "initcond");
                } else{
                    initialComparison = llvmBuilder->CreateICmpSLT(initialValue, endValue, "initcond");
                }
                llvmBuilder->CreateCondBr(initialComparison, loopBlock, afterBlock);
                llvmBuilder->SetInsertPoint(loopBlock);
            } else if(ctx->parent && static_cast<antlr4::ParserRuleContext*>(ctx->parent)->getRuleIndex()==testLanguageParser::RuleIfStatement){
                auto ifStatement = static_cast<testLanguageParser::IfStatementContext*>(ctx->parent);
                testLanguageParser::ScopeBlockContext* thenBlockContext = nullptr;
                testLanguageParser::ScopeBlockContext* elseBlockContext = nullptr;
                Function* currentBlock  = llvmBuilder->GetInsertBlock()->getParent();
                BasicBlock* afterBlock = static_cast<BasicBlock*>(values.get(ifStatement));
                thenBlockContext = ifStatement->scopeBlock(0);
                if(ifStatement->scopeBlock().size()==2){
                    elseBlockContext = ifStatement->scopeBlock(1);
                }
                if(thenBlockContext && *ctx==*thenBlockContext){
                    BasicBlock* thenBlock   = BasicBlock::Create(*llvmContext, "thenblk", currentBlock, afterBlock);
                    values.put(ifStatement->Then(), thenBlock);
                    scopeList.push_front(Scope(thenBlock));
                    llvmBuilder->SetInsertPoint(thenBlock);
                } else if(elseBlockContext && *ctx==*elseBlockContext){
                    BasicBlock* elseBlock   = BasicBlock::Create(*llvmContext, "elseblk", currentBlock, afterBlock);
                    values.put(ifStatement->Else(), elseBlock);
                    scopeList.push_front(Scope(elseBlock));
                    llvmBuilder->SetInsertPoint(elseBlock);
                } else{
                    errs()<<ifStatement->getText()<<"\n";
                    errs()<<"We're entering a scope block that's neither the then nor the else one, something went wrong.\n";
                    return;
                }
            } else{
                scopeList.push_front(Scope(llvmBuilder->GetInsertBlock(), ""));
            }
        }

        void exitScopeBlock(testLanguageParser::ScopeBlockContext *ctx) override{
            if(ctx->parent && static_cast<antlr4::ParserRuleContext*>(ctx->parent)->getRuleIndex()==testLanguageParser::RuleFunction_declaration){
                testLanguageParser::Function_declarationContext* functx = static_cast<testLanguageParser::Function_declarationContext*>(ctx->parent);
                BasicBlock* afterBlock = static_cast<BasicBlock*>(values.get(functx->scopeBlock()));
                Function* function = findFunction(functx->Id()->getText());
                if(!function){
                    errs()<<functx->Func()->getText()<<" "<<functx->Id()->getText()<<" "<<functx->function_type()->getText()<<"\n";
                    errs()<<"The definition for function "<<functx->Id()->getText()<<" failed, can't attach its body.\n";
                    llvmBuilder->SetInsertPoint(afterBlock);
                    return;
                }
                Value* returnVar;
                auto returns = functx->function_type()->formal_parameter_list(1)->formal_parameter();
                if(function->getReturnType()->isStructTy()){
                    std::vector<Value*> retValues(returns.size());
                    returnVar = allocVariable(function->getReturnType(), "_" + functx->Id()->getText() + "_return");
                    int index = 0;
                    std::vector<Value*> indexes(2);
                    indexes[0] =  ConstantInt::get(*llvmContext, APInt(32, 0));
                    for(auto &retType : static_cast<StructType*>(function->getReturnType())->elements()){
                        AllocaInst* ret = findVariable(returns[index]->Id()->getText());
                        if(!ret){
                            errs()<<"On returning from function "<<functx->Id()->getText()<<": declaration of return variable "<<returns[index]->Id()->getText()<<" failed, so can't build the return value.\n";
                            return;
                        }
                        retValues[index] = llvmBuilder->CreateLoad(retType, ret, returns[index]->Id()->getText());
                        indexes[1] = ConstantInt::get(*llvmContext, APInt(32, index));
                        Value* gepIndex = llvmBuilder->CreateGEP(returnVar->getType()->getPointerElementType(), returnVar, indexes);
                        llvmBuilder->CreateStore(retValues[index], gepIndex);
                        index++;
                    }
                } else{
                    returnVar = scopeList.front().variables[returns[0]->Id()->getText()];
                    //TODO Do something for function types
                }
                BasicBlock* functionBlock = llvmBuilder->GetInsertBlock();
                if(scopeList.front().deferBlock){
                    while(scopeList.front().deferBlock->begin()!=scopeList.front().deferBlock->end()){
                        auto defer = &*scopeList.front().deferBlock->begin();
                        defer->removeFromParent();
                        functionBlock->getInstList().push_back(defer);
                    }
                    scopeList.front().deferBlock->eraseFromParent();
                }
                Value* returnValue = llvmBuilder->CreateLoad(function->getReturnType(), returnVar, "retVal");
                llvmBuilder->CreateRet(returnValue);
                verifyFunction(*function);
                llvmBuilder->SetInsertPoint(afterBlock);
            } else if(ctx->parent && static_cast<antlr4::ParserRuleContext*>(ctx->parent)->getRuleIndex()==testLanguageParser::RuleForStatement){
                auto forStatement = static_cast<testLanguageParser::ForStatementContext*>(ctx->parent);
                std::string loopIndexVarName = "_loopindex";
                if(forStatement->forVariable(0)->Id()){
                    loopIndexVarName = forStatement->forVariable(0)->Id()->getText();
                }
                AllocaInst* loopIndexVar = scopeList.front().variables[loopIndexVarName];
                Value* indexedVar;
                if(forStatement->expression()){
                   indexedVar = values.get(forStatement->expression());
                }
                AllocaInst* iteratorVar;
                if(forStatement->expression() &&forStatement->forVariable(1)->Id()){
                    iteratorVar = scopeList.front().variables[forStatement->forVariable(1)->Id()->getText()];
                }
                Value* stepValue;
                if(forStatement->In()){
                    stepValue = values.get(forStatement->In());
                } else{
                    stepValue = values.get(forStatement->range());
                }
                Value* curLoopIndexVarValue = llvmBuilder->CreateLoad(loopIndexVar->getType()->getPointerElementType(), loopIndexVar, loopIndexVarName);
                Value* nextLoopIndexVarValue;
                if(forStatement->Reverse()){
                    nextLoopIndexVarValue = llvmBuilder->CreateSub(curLoopIndexVarValue, stepValue, "indexnext");
                } else{
                    nextLoopIndexVarValue = llvmBuilder->CreateAdd(curLoopIndexVarValue, stepValue, "indexnext");
                }
                llvmBuilder->CreateStore(nextLoopIndexVarValue, loopIndexVar);
                Value* endValue    = values.get(forStatement->forVariable(0));
                if(forStatement->forVariable(1)->Id()){
                    Value* currentIteratorVal = llvmBuilder->CreateLoad(iteratorVar->getType()->getPointerElementType(), iteratorVar, "iterload");
                    llvmBuilder->CreateInsertElement(indexedVar, currentIteratorVal, curLoopIndexVarValue, "iterupdate");
                    Value* nextIteratorValue = llvmBuilder->CreateExtractElement(indexedVar, nextLoopIndexVarValue, "iternext");
                    llvmBuilder->CreateStore(nextIteratorValue, iteratorVar);
                }
                BasicBlock* loopBlock   = llvmBuilder->GetInsertBlock();
                Value* endCondition;
                if(forStatement->Reverse()){
                    endCondition = llvmBuilder->CreateICmpSLT(endValue, nextLoopIndexVarValue, "loopcond");
                } else{
                    endCondition = llvmBuilder->CreateICmpSLT(nextLoopIndexVarValue, endValue, "loopcon");
                }
                if(scopeList.front().deferBlock){
                while(scopeList.front().deferBlock->begin()!=scopeList.front().deferBlock->end()){
                    auto defer = &*scopeList.front().deferBlock->begin();
                    defer->removeFromParent();
                    loopBlock->getInstList().push_back(defer);
                }
                scopeList.front().deferBlock->eraseFromParent();
                }
                BasicBlock* afterBlock  = static_cast<BasicBlock*>(values.get(ctx));
                llvmBuilder->CreateCondBr(endCondition, loopBlock, afterBlock);
                llvmBuilder->SetInsertPoint(afterBlock);
            } else if(ctx->parent && static_cast<antlr4::ParserRuleContext*>(ctx->parent)->getRuleIndex()==testLanguageParser::RuleIfStatement){
                auto ifStatement = static_cast<testLanguageParser::IfStatementContext*>(ctx->parent);
                BasicBlock* afterBlock = static_cast<BasicBlock*>(values.get(ifStatement));
                llvmBuilder->CreateBr(afterBlock);
            } 
            if(scopeList.front().deferBlock){
                BasicBlock* scopeBlock   = llvmBuilder->GetInsertBlock();
                while(scopeList.front().deferBlock->begin()!=scopeList.front().deferBlock->end()){
                    auto defer = &*scopeList.front().deferBlock->begin();
                    defer->removeFromParent();
                    scopeBlock->getInstList().push_back(defer);
                }
                scopeList.front().deferBlock->eraseFromParent();
            }
            scopeList.pop_front();
        }

        void enterIfStatement(testLanguageParser::IfStatementContext *ctx) override{
            Function* currentBlock  = llvmBuilder->GetInsertBlock()->getParent();
            BasicBlock* afterBlock  = BasicBlock::Create(*llvmContext, "afterif", currentBlock);
            values.put(ctx, afterBlock);
            values.put(ctx->If(), llvmBuilder->GetInsertBlock());
        }
        
        void exitIfStatement(testLanguageParser::IfStatementContext *ctx) override{
            BasicBlock* beforeBlock = static_cast<BasicBlock*>(values.get(ctx->If()));
            BasicBlock* thenBlock = static_cast<BasicBlock*>(values.get(ctx->Then()));
            BasicBlock* elseBlock = static_cast<BasicBlock*>(values.get(ctx->Else()));
            BasicBlock* afterBlock  = static_cast<BasicBlock*>(values.get(ctx));
            Value* ifValue = values.get(ctx->expression());
            Value* ifCond;
            llvmBuilder->SetInsertPoint(beforeBlock);
            if(ifValue->getType()==Type::getInt1Ty(*llvmContext)){
                ifCond = ifValue;
            } else if(ifValue->getType()->isIntegerTy()){
                ifCond = llvmBuilder->CreateICmpNE(ifValue, ConstantInt::get(ifValue->getType(), 0), "ifcond");
            } else if(ifValue->getType()->isFloatTy()){
                ifCond = llvmBuilder->CreateFCmpUNE(ifValue, ConstantFP::get(ifValue->getType(), 0.), "ifcond");
            } else{
                errs()<<ctx->getText()<<"\n";
                errs()<<"Expression " << ctx->expression()->getText() << "can't be checked for truth value.\n";
                llvmBuilder->SetInsertPoint(afterBlock);
                return;
            }
            llvmBuilder->CreateCondBr(ifCond, thenBlock, elseBlock ? elseBlock : afterBlock);
            llvmBuilder->SetInsertPoint(afterBlock);
        }
};

int main(int argc, char *argv[]){
    if(argc!=2){
        std::cout<<"We only support providing one input file"<<std::endl;
        return -1;
    }
    std::ifstream stream;
    stream.open(argv[1]);
    if(!stream.good()){
        std::cout<<"Error reading file "<<argv[1]<<std::endl;
    }
    ANTLRInputStream input(stream);
    testLanguageLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    testLanguageParser parser(&tokens);
    tree::ParseTree *tree = parser.program();
    TreeShapeListener listener;
    tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);

     // Initialize the target registry etc.
    InitializeAllTargetInfos();
    InitializeAllTargets();
    InitializeAllTargetMCs();
    InitializeAllAsmParsers();
    InitializeAllAsmPrinters();

    auto TargetTriple = sys::getDefaultTargetTriple();
    listener.llvmModule->setTargetTriple(TargetTriple);

    std::string Error;
    auto Target = TargetRegistry::lookupTarget(TargetTriple, Error);

    // Print an error and exit if we couldn't find the requested target.
    // This generally occurs if we've forgotten to initialise the
    // TargetRegistry or we have a bogus target triple.
    if (!Target) {
        errs() << Error;
        return 1;
    }

    auto CPU = "generic";
    auto Features = "";

    TargetOptions opt;
    auto RM = Optional<Reloc::Model>();
    auto TheTargetMachine =
        Target->createTargetMachine(TargetTriple, CPU, Features, opt, RM);

    listener.llvmModule->setDataLayout(TheTargetMachine->createDataLayout());

    std::string filename = std::string(argv[1]) + ".ll";
    std::error_code ec;
    llvm::sys::fs::CreationDisposition flags = llvm::sys::fs::CreationDisposition::CD_CreateAlways;
    raw_fd_ostream os(filename, ec, flags);
    if(ec.value()!=0){
        std::cout<<"Failed to open file "<<filename<<" because of error: "<<ec.message()<<", exiting."<<std::endl;
        os.close();
        return -1;
    }
    listener.llvmModule->print(os, nullptr);

    return 0;
}

