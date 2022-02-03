
// Generated from testLanguage.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"




class  testLanguageParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, Whitespace = 14, 
    Newline = 15, Defer = 16, Func = 17, If = 18, Then = 19, Else = 20, 
    For = 21, From = 22, To = 23, In = 24, By = 25, Reverse = 26, Var = 27, 
    Slash = 28, Star = 29, Plus = 30, Minus = 31, LessOrEqual = 32, Less = 33, 
    GreaterOrEqual = 34, Greater = 35, Equal = 36, NotEqual = 37, Negation = 38, 
    Or = 39, And = 40, Xor = 41, Type = 42, Id = 43, Integer = 44, Float = 45
  };

  enum {
    RuleProgram = 0, RuleStatement = 1, RuleDefer_statement = 2, RuleType = 3, 
    RuleFormal_parameter = 4, RuleFormal_parameter_list = 5, RuleVariable_type = 6, 
    RuleFunction_type = 7, RuleId_declaration = 8, RuleFunction_declaration = 9, 
    RuleVariable_type_declaration = 10, RuleFunction_type_declaration = 11, 
    RuleType_declaration = 12, RuleDeclaration = 13, RuleMember_access = 14, 
    RuleAssignment = 15, RuleExpression = 16, RuleScopeBlock = 17, RuleForVariable = 18, 
    RuleByClause = 19, RuleRange = 20, RuleForStatement = 21, RuleIfStatement = 22
  };

  explicit testLanguageParser(antlr4::TokenStream *input);
  ~testLanguageParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class ProgramContext;
  class StatementContext;
  class Defer_statementContext;
  class TypeContext;
  class Formal_parameterContext;
  class Formal_parameter_listContext;
  class Variable_typeContext;
  class Function_typeContext;
  class Id_declarationContext;
  class Function_declarationContext;
  class Variable_type_declarationContext;
  class Function_type_declarationContext;
  class Type_declarationContext;
  class DeclarationContext;
  class Member_accessContext;
  class AssignmentContext;
  class ExpressionContext;
  class ScopeBlockContext;
  class ForVariableContext;
  class ByClauseContext;
  class RangeContext;
  class ForStatementContext;
  class IfStatementContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);
    std::vector<Defer_statementContext *> defer_statement();
    Defer_statementContext* defer_statement(size_t i);
    std::vector<ScopeBlockContext *> scopeBlock();
    ScopeBlockContext* scopeBlock(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ProgramContext* program();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    DeclarationContext *declaration();
    AssignmentContext *assignment();
    ForStatementContext *forStatement();
    IfStatementContext *ifStatement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StatementContext* statement();

  class  Defer_statementContext : public antlr4::ParserRuleContext {
  public:
    Defer_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Defer();
    StatementContext *statement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Defer_statementContext* defer_statement();

  class  TypeContext : public antlr4::ParserRuleContext {
  public:
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Variable_typeContext *variable_type();
    Function_typeContext *function_type();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TypeContext* type();

  class  Formal_parameterContext : public antlr4::ParserRuleContext {
  public:
    Formal_parameterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Id();
    Variable_typeContext *variable_type();
    antlr4::tree::TerminalNode *Var();
    Function_typeContext *function_type();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Formal_parameterContext* formal_parameter();

  class  Formal_parameter_listContext : public antlr4::ParserRuleContext {
  public:
    Formal_parameter_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Formal_parameterContext *> formal_parameter();
    Formal_parameterContext* formal_parameter(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Formal_parameter_listContext* formal_parameter_list();

  class  Variable_typeContext : public antlr4::ParserRuleContext {
  public:
    Variable_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Type();
    antlr4::tree::TerminalNode *Integer();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Variable_typeContext* variable_type();

  class  Function_typeContext : public antlr4::ParserRuleContext {
  public:
    Function_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Formal_parameter_listContext *> formal_parameter_list();
    Formal_parameter_listContext* formal_parameter_list(size_t i);
    antlr4::tree::TerminalNode *Type();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Function_typeContext* function_type();

  class  Id_declarationContext : public antlr4::ParserRuleContext {
  public:
    Id_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> Id();
    antlr4::tree::TerminalNode* Id(size_t i);
    Variable_typeContext *variable_type();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Id_declarationContext* id_declaration();

  class  Function_declarationContext : public antlr4::ParserRuleContext {
  public:
    Function_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Func();
    antlr4::tree::TerminalNode *Id();
    Function_typeContext *function_type();
    ScopeBlockContext *scopeBlock();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Function_declarationContext* function_declaration();

  class  Variable_type_declarationContext : public antlr4::ParserRuleContext {
  public:
    Variable_type_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Type();
    std::vector<Variable_typeContext *> variable_type();
    Variable_typeContext* variable_type(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Id();
    antlr4::tree::TerminalNode* Id(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Variable_type_declarationContext* variable_type_declaration();

  class  Function_type_declarationContext : public antlr4::ParserRuleContext {
  public:
    Function_type_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Type();
    Function_typeContext *function_type();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Function_type_declarationContext* function_type_declaration();

  class  Type_declarationContext : public antlr4::ParserRuleContext {
  public:
    Type_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Variable_type_declarationContext *variable_type_declaration();
    Function_type_declarationContext *function_type_declaration();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Type_declarationContext* type_declaration();

  class  DeclarationContext : public antlr4::ParserRuleContext {
  public:
    DeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Id_declarationContext *id_declaration();
    Function_declarationContext *function_declaration();
    Type_declarationContext *type_declaration();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  DeclarationContext* declaration();

  class  Member_accessContext : public antlr4::ParserRuleContext {
  public:
    Member_accessContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> Id();
    antlr4::tree::TerminalNode* Id(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Member_accessContext* member_access();

  class  AssignmentContext : public antlr4::ParserRuleContext {
  public:
    AssignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> Id();
    antlr4::tree::TerminalNode* Id(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<Member_accessContext *> member_access();
    Member_accessContext* member_access(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AssignmentContext* assignment();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExpressionContext() = default;
    void copyFrom(ExpressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Constant_integer_expressionContext : public ExpressionContext {
  public:
    Constant_integer_expressionContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *Integer();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  Function_callContext : public ExpressionContext {
  public:
    Function_callContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *Id();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  Constant_float_expressionContext : public ExpressionContext {
  public:
    Constant_float_expressionContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *Float();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  Init_expressionContext : public ExpressionContext {
  public:
    Init_expressionContext(ExpressionContext *ctx);

    Variable_typeContext *variable_type();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  Multiply_expressionContext : public ExpressionContext {
  public:
    Multiply_expressionContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *Star();
    antlr4::tree::TerminalNode *Slash();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  Sum_expressionContext : public ExpressionContext {
  public:
    Sum_expressionContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *Plus();
    antlr4::tree::TerminalNode *Minus();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  Comparison_expressionContext : public ExpressionContext {
  public:
    Comparison_expressionContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *LessOrEqual();
    antlr4::tree::TerminalNode *Less();
    antlr4::tree::TerminalNode *GreaterOrEqual();
    antlr4::tree::TerminalNode *Greater();
    antlr4::tree::TerminalNode *Equal();
    antlr4::tree::TerminalNode *NotEqual();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  Variable_expressionContext : public ExpressionContext {
  public:
    Variable_expressionContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *Id();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  Invert_sign_expressionContext : public ExpressionContext {
  public:
    Invert_sign_expressionContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *Minus();
    ExpressionContext *expression();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  Negation_expressionContext : public ExpressionContext {
  public:
    Negation_expressionContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *Negation();
    ExpressionContext *expression();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  Parenthesized_expressionContext : public ExpressionContext {
  public:
    Parenthesized_expressionContext(ExpressionContext *ctx);

    ExpressionContext *expression();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  Member_access_expressionContext : public ExpressionContext {
  public:
    Member_access_expressionContext(ExpressionContext *ctx);

    Member_accessContext *member_access();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  Logical_expressionContext : public ExpressionContext {
  public:
    Logical_expressionContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *Or();
    antlr4::tree::TerminalNode *And();
    antlr4::tree::TerminalNode *Xor();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  ExpressionContext* expression();
  ExpressionContext* expression(int precedence);
  class  ScopeBlockContext : public antlr4::ParserRuleContext {
  public:
    ScopeBlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);
    std::vector<ScopeBlockContext *> scopeBlock();
    ScopeBlockContext* scopeBlock(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ScopeBlockContext* scopeBlock();

  class  ForVariableContext : public antlr4::ParserRuleContext {
  public:
    ForVariableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Id();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ForVariableContext* forVariable();

  class  ByClauseContext : public antlr4::ParserRuleContext {
  public:
    ByClauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *By();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ByClauseContext* byClause();

  class  RangeContext : public antlr4::ParserRuleContext {
  public:
    RangeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *From();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *To();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  RangeContext* range();

  class  ForStatementContext : public antlr4::ParserRuleContext {
  public:
    ForStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *For();
    std::vector<ForVariableContext *> forVariable();
    ForVariableContext* forVariable(size_t i);
    ScopeBlockContext *scopeBlock();
    antlr4::tree::TerminalNode *In();
    ExpressionContext *expression();
    RangeContext *range();
    ByClauseContext *byClause();
    antlr4::tree::TerminalNode *Reverse();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ForStatementContext* forStatement();

  class  IfStatementContext : public antlr4::ParserRuleContext {
  public:
    IfStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *If();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *Then();
    std::vector<ScopeBlockContext *> scopeBlock();
    ScopeBlockContext* scopeBlock(size_t i);
    antlr4::tree::TerminalNode *Else();
    IfStatementContext *ifStatement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  IfStatementContext* ifStatement();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool expressionSempred(ExpressionContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

