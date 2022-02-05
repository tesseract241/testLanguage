
// Generated from testLanguage.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"
#include "testLanguageListener.h"


/**
 * This class provides an empty implementation of testLanguageListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  testLanguageBaseListener : public testLanguageListener {
public:

  virtual void enterProgram(testLanguageParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(testLanguageParser::ProgramContext * /*ctx*/) override { }

  virtual void enterStatement(testLanguageParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(testLanguageParser::StatementContext * /*ctx*/) override { }

  virtual void enterDefer_statement(testLanguageParser::Defer_statementContext * /*ctx*/) override { }
  virtual void exitDefer_statement(testLanguageParser::Defer_statementContext * /*ctx*/) override { }

  virtual void enterType(testLanguageParser::TypeContext * /*ctx*/) override { }
  virtual void exitType(testLanguageParser::TypeContext * /*ctx*/) override { }

  virtual void enterFormal_parameter(testLanguageParser::Formal_parameterContext * /*ctx*/) override { }
  virtual void exitFormal_parameter(testLanguageParser::Formal_parameterContext * /*ctx*/) override { }

  virtual void enterFormal_parameter_list(testLanguageParser::Formal_parameter_listContext * /*ctx*/) override { }
  virtual void exitFormal_parameter_list(testLanguageParser::Formal_parameter_listContext * /*ctx*/) override { }

  virtual void enterVariable_type(testLanguageParser::Variable_typeContext * /*ctx*/) override { }
  virtual void exitVariable_type(testLanguageParser::Variable_typeContext * /*ctx*/) override { }

  virtual void enterFunction_type(testLanguageParser::Function_typeContext * /*ctx*/) override { }
  virtual void exitFunction_type(testLanguageParser::Function_typeContext * /*ctx*/) override { }

  virtual void enterId_declaration(testLanguageParser::Id_declarationContext * /*ctx*/) override { }
  virtual void exitId_declaration(testLanguageParser::Id_declarationContext * /*ctx*/) override { }

  virtual void enterFunction_declaration(testLanguageParser::Function_declarationContext * /*ctx*/) override { }
  virtual void exitFunction_declaration(testLanguageParser::Function_declarationContext * /*ctx*/) override { }

  virtual void enterVariable_type_declaration(testLanguageParser::Variable_type_declarationContext * /*ctx*/) override { }
  virtual void exitVariable_type_declaration(testLanguageParser::Variable_type_declarationContext * /*ctx*/) override { }

  virtual void enterFunction_type_declaration(testLanguageParser::Function_type_declarationContext * /*ctx*/) override { }
  virtual void exitFunction_type_declaration(testLanguageParser::Function_type_declarationContext * /*ctx*/) override { }

  virtual void enterType_declaration(testLanguageParser::Type_declarationContext * /*ctx*/) override { }
  virtual void exitType_declaration(testLanguageParser::Type_declarationContext * /*ctx*/) override { }

  virtual void enterDeclaration(testLanguageParser::DeclarationContext * /*ctx*/) override { }
  virtual void exitDeclaration(testLanguageParser::DeclarationContext * /*ctx*/) override { }

  virtual void enterMember_access(testLanguageParser::Member_accessContext * /*ctx*/) override { }
  virtual void exitMember_access(testLanguageParser::Member_accessContext * /*ctx*/) override { }

  virtual void enterAssignment(testLanguageParser::AssignmentContext * /*ctx*/) override { }
  virtual void exitAssignment(testLanguageParser::AssignmentContext * /*ctx*/) override { }

  virtual void enterConstant_integer_expression(testLanguageParser::Constant_integer_expressionContext * /*ctx*/) override { }
  virtual void exitConstant_integer_expression(testLanguageParser::Constant_integer_expressionContext * /*ctx*/) override { }

  virtual void enterFunction_call(testLanguageParser::Function_callContext * /*ctx*/) override { }
  virtual void exitFunction_call(testLanguageParser::Function_callContext * /*ctx*/) override { }

  virtual void enterConstant_float_expression(testLanguageParser::Constant_float_expressionContext * /*ctx*/) override { }
  virtual void exitConstant_float_expression(testLanguageParser::Constant_float_expressionContext * /*ctx*/) override { }

  virtual void enterInit_expression(testLanguageParser::Init_expressionContext * /*ctx*/) override { }
  virtual void exitInit_expression(testLanguageParser::Init_expressionContext * /*ctx*/) override { }

  virtual void enterMultiply_expression(testLanguageParser::Multiply_expressionContext * /*ctx*/) override { }
  virtual void exitMultiply_expression(testLanguageParser::Multiply_expressionContext * /*ctx*/) override { }

  virtual void enterSum_expression(testLanguageParser::Sum_expressionContext * /*ctx*/) override { }
  virtual void exitSum_expression(testLanguageParser::Sum_expressionContext * /*ctx*/) override { }

  virtual void enterComparison_expression(testLanguageParser::Comparison_expressionContext * /*ctx*/) override { }
  virtual void exitComparison_expression(testLanguageParser::Comparison_expressionContext * /*ctx*/) override { }

  virtual void enterVariable_expression(testLanguageParser::Variable_expressionContext * /*ctx*/) override { }
  virtual void exitVariable_expression(testLanguageParser::Variable_expressionContext * /*ctx*/) override { }

  virtual void enterInvert_sign_expression(testLanguageParser::Invert_sign_expressionContext * /*ctx*/) override { }
  virtual void exitInvert_sign_expression(testLanguageParser::Invert_sign_expressionContext * /*ctx*/) override { }

  virtual void enterNegation_expression(testLanguageParser::Negation_expressionContext * /*ctx*/) override { }
  virtual void exitNegation_expression(testLanguageParser::Negation_expressionContext * /*ctx*/) override { }

  virtual void enterParenthesized_expression(testLanguageParser::Parenthesized_expressionContext * /*ctx*/) override { }
  virtual void exitParenthesized_expression(testLanguageParser::Parenthesized_expressionContext * /*ctx*/) override { }

  virtual void enterMember_access_expression(testLanguageParser::Member_access_expressionContext * /*ctx*/) override { }
  virtual void exitMember_access_expression(testLanguageParser::Member_access_expressionContext * /*ctx*/) override { }

  virtual void enterLogical_expression(testLanguageParser::Logical_expressionContext * /*ctx*/) override { }
  virtual void exitLogical_expression(testLanguageParser::Logical_expressionContext * /*ctx*/) override { }

  virtual void enterScopeBlock(testLanguageParser::ScopeBlockContext * /*ctx*/) override { }
  virtual void exitScopeBlock(testLanguageParser::ScopeBlockContext * /*ctx*/) override { }

  virtual void enterForVariable(testLanguageParser::ForVariableContext * /*ctx*/) override { }
  virtual void exitForVariable(testLanguageParser::ForVariableContext * /*ctx*/) override { }

  virtual void enterByClause(testLanguageParser::ByClauseContext * /*ctx*/) override { }
  virtual void exitByClause(testLanguageParser::ByClauseContext * /*ctx*/) override { }

  virtual void enterRange(testLanguageParser::RangeContext * /*ctx*/) override { }
  virtual void exitRange(testLanguageParser::RangeContext * /*ctx*/) override { }

  virtual void enterForStatement(testLanguageParser::ForStatementContext * /*ctx*/) override { }
  virtual void exitForStatement(testLanguageParser::ForStatementContext * /*ctx*/) override { }

  virtual void enterIfStatement(testLanguageParser::IfStatementContext * /*ctx*/) override { }
  virtual void exitIfStatement(testLanguageParser::IfStatementContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

