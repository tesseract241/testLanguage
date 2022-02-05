
// Generated from testLanguage.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"
#include "testLanguageParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by testLanguageParser.
 */
class  testLanguageListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(testLanguageParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(testLanguageParser::ProgramContext *ctx) = 0;

  virtual void enterStatement(testLanguageParser::StatementContext *ctx) = 0;
  virtual void exitStatement(testLanguageParser::StatementContext *ctx) = 0;

  virtual void enterDefer_statement(testLanguageParser::Defer_statementContext *ctx) = 0;
  virtual void exitDefer_statement(testLanguageParser::Defer_statementContext *ctx) = 0;

  virtual void enterType(testLanguageParser::TypeContext *ctx) = 0;
  virtual void exitType(testLanguageParser::TypeContext *ctx) = 0;

  virtual void enterFormal_parameter(testLanguageParser::Formal_parameterContext *ctx) = 0;
  virtual void exitFormal_parameter(testLanguageParser::Formal_parameterContext *ctx) = 0;

  virtual void enterFormal_parameter_list(testLanguageParser::Formal_parameter_listContext *ctx) = 0;
  virtual void exitFormal_parameter_list(testLanguageParser::Formal_parameter_listContext *ctx) = 0;

  virtual void enterVariable_type(testLanguageParser::Variable_typeContext *ctx) = 0;
  virtual void exitVariable_type(testLanguageParser::Variable_typeContext *ctx) = 0;

  virtual void enterFunction_type(testLanguageParser::Function_typeContext *ctx) = 0;
  virtual void exitFunction_type(testLanguageParser::Function_typeContext *ctx) = 0;

  virtual void enterId_declaration(testLanguageParser::Id_declarationContext *ctx) = 0;
  virtual void exitId_declaration(testLanguageParser::Id_declarationContext *ctx) = 0;

  virtual void enterFunction_declaration(testLanguageParser::Function_declarationContext *ctx) = 0;
  virtual void exitFunction_declaration(testLanguageParser::Function_declarationContext *ctx) = 0;

  virtual void enterVariable_type_declaration(testLanguageParser::Variable_type_declarationContext *ctx) = 0;
  virtual void exitVariable_type_declaration(testLanguageParser::Variable_type_declarationContext *ctx) = 0;

  virtual void enterFunction_type_declaration(testLanguageParser::Function_type_declarationContext *ctx) = 0;
  virtual void exitFunction_type_declaration(testLanguageParser::Function_type_declarationContext *ctx) = 0;

  virtual void enterType_declaration(testLanguageParser::Type_declarationContext *ctx) = 0;
  virtual void exitType_declaration(testLanguageParser::Type_declarationContext *ctx) = 0;

  virtual void enterDeclaration(testLanguageParser::DeclarationContext *ctx) = 0;
  virtual void exitDeclaration(testLanguageParser::DeclarationContext *ctx) = 0;

  virtual void enterMember_access(testLanguageParser::Member_accessContext *ctx) = 0;
  virtual void exitMember_access(testLanguageParser::Member_accessContext *ctx) = 0;

  virtual void enterAssignment(testLanguageParser::AssignmentContext *ctx) = 0;
  virtual void exitAssignment(testLanguageParser::AssignmentContext *ctx) = 0;

  virtual void enterConstant_integer_expression(testLanguageParser::Constant_integer_expressionContext *ctx) = 0;
  virtual void exitConstant_integer_expression(testLanguageParser::Constant_integer_expressionContext *ctx) = 0;

  virtual void enterFunction_call(testLanguageParser::Function_callContext *ctx) = 0;
  virtual void exitFunction_call(testLanguageParser::Function_callContext *ctx) = 0;

  virtual void enterConstant_float_expression(testLanguageParser::Constant_float_expressionContext *ctx) = 0;
  virtual void exitConstant_float_expression(testLanguageParser::Constant_float_expressionContext *ctx) = 0;

  virtual void enterInit_expression(testLanguageParser::Init_expressionContext *ctx) = 0;
  virtual void exitInit_expression(testLanguageParser::Init_expressionContext *ctx) = 0;

  virtual void enterMultiply_expression(testLanguageParser::Multiply_expressionContext *ctx) = 0;
  virtual void exitMultiply_expression(testLanguageParser::Multiply_expressionContext *ctx) = 0;

  virtual void enterSum_expression(testLanguageParser::Sum_expressionContext *ctx) = 0;
  virtual void exitSum_expression(testLanguageParser::Sum_expressionContext *ctx) = 0;

  virtual void enterComparison_expression(testLanguageParser::Comparison_expressionContext *ctx) = 0;
  virtual void exitComparison_expression(testLanguageParser::Comparison_expressionContext *ctx) = 0;

  virtual void enterVariable_expression(testLanguageParser::Variable_expressionContext *ctx) = 0;
  virtual void exitVariable_expression(testLanguageParser::Variable_expressionContext *ctx) = 0;

  virtual void enterInvert_sign_expression(testLanguageParser::Invert_sign_expressionContext *ctx) = 0;
  virtual void exitInvert_sign_expression(testLanguageParser::Invert_sign_expressionContext *ctx) = 0;

  virtual void enterNegation_expression(testLanguageParser::Negation_expressionContext *ctx) = 0;
  virtual void exitNegation_expression(testLanguageParser::Negation_expressionContext *ctx) = 0;

  virtual void enterParenthesized_expression(testLanguageParser::Parenthesized_expressionContext *ctx) = 0;
  virtual void exitParenthesized_expression(testLanguageParser::Parenthesized_expressionContext *ctx) = 0;

  virtual void enterMember_access_expression(testLanguageParser::Member_access_expressionContext *ctx) = 0;
  virtual void exitMember_access_expression(testLanguageParser::Member_access_expressionContext *ctx) = 0;

  virtual void enterLogical_expression(testLanguageParser::Logical_expressionContext *ctx) = 0;
  virtual void exitLogical_expression(testLanguageParser::Logical_expressionContext *ctx) = 0;

  virtual void enterScopeBlock(testLanguageParser::ScopeBlockContext *ctx) = 0;
  virtual void exitScopeBlock(testLanguageParser::ScopeBlockContext *ctx) = 0;

  virtual void enterForVariable(testLanguageParser::ForVariableContext *ctx) = 0;
  virtual void exitForVariable(testLanguageParser::ForVariableContext *ctx) = 0;

  virtual void enterByClause(testLanguageParser::ByClauseContext *ctx) = 0;
  virtual void exitByClause(testLanguageParser::ByClauseContext *ctx) = 0;

  virtual void enterRange(testLanguageParser::RangeContext *ctx) = 0;
  virtual void exitRange(testLanguageParser::RangeContext *ctx) = 0;

  virtual void enterForStatement(testLanguageParser::ForStatementContext *ctx) = 0;
  virtual void exitForStatement(testLanguageParser::ForStatementContext *ctx) = 0;

  virtual void enterIfStatement(testLanguageParser::IfStatementContext *ctx) = 0;
  virtual void exitIfStatement(testLanguageParser::IfStatementContext *ctx) = 0;


};

