
// Generated from testLanguage.g4 by ANTLR 4.9.3


#include "testLanguageListener.h"

#include "testLanguageParser.h"


using namespace antlrcpp;
using namespace antlr4;

testLanguageParser::testLanguageParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

testLanguageParser::~testLanguageParser() {
  delete _interpreter;
}

std::string testLanguageParser::getGrammarFileName() const {
  return "testLanguage.g4";
}

const std::vector<std::string>& testLanguageParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& testLanguageParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

testLanguageParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<testLanguageParser::StatementContext *> testLanguageParser::ProgramContext::statement() {
  return getRuleContexts<testLanguageParser::StatementContext>();
}

testLanguageParser::StatementContext* testLanguageParser::ProgramContext::statement(size_t i) {
  return getRuleContext<testLanguageParser::StatementContext>(i);
}

std::vector<testLanguageParser::Defer_statementContext *> testLanguageParser::ProgramContext::defer_statement() {
  return getRuleContexts<testLanguageParser::Defer_statementContext>();
}

testLanguageParser::Defer_statementContext* testLanguageParser::ProgramContext::defer_statement(size_t i) {
  return getRuleContext<testLanguageParser::Defer_statementContext>(i);
}

std::vector<testLanguageParser::ScopeBlockContext *> testLanguageParser::ProgramContext::scopeBlock() {
  return getRuleContexts<testLanguageParser::ScopeBlockContext>();
}

testLanguageParser::ScopeBlockContext* testLanguageParser::ProgramContext::scopeBlock(size_t i) {
  return getRuleContext<testLanguageParser::ScopeBlockContext>(i);
}


size_t testLanguageParser::ProgramContext::getRuleIndex() const {
  return testLanguageParser::RuleProgram;
}

void testLanguageParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void testLanguageParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}

testLanguageParser::ProgramContext* testLanguageParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, testLanguageParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(49); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(49);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case testLanguageParser::T__0:
        case testLanguageParser::T__4:
        case testLanguageParser::T__8:
        case testLanguageParser::Func:
        case testLanguageParser::If:
        case testLanguageParser::For:
        case testLanguageParser::Minus:
        case testLanguageParser::Negation:
        case testLanguageParser::Type:
        case testLanguageParser::Id:
        case testLanguageParser::Integer:
        case testLanguageParser::Float: {
          setState(46);
          statement();
          break;
        }

        case testLanguageParser::Defer: {
          setState(47);
          defer_statement();
          break;
        }

        case testLanguageParser::T__9: {
          setState(48);
          scopeBlock();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(51); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << testLanguageParser::T__0)
      | (1ULL << testLanguageParser::T__4)
      | (1ULL << testLanguageParser::T__8)
      | (1ULL << testLanguageParser::T__9)
      | (1ULL << testLanguageParser::Defer)
      | (1ULL << testLanguageParser::Func)
      | (1ULL << testLanguageParser::If)
      | (1ULL << testLanguageParser::For)
      | (1ULL << testLanguageParser::Minus)
      | (1ULL << testLanguageParser::Negation)
      | (1ULL << testLanguageParser::Type)
      | (1ULL << testLanguageParser::Id)
      | (1ULL << testLanguageParser::Integer)
      | (1ULL << testLanguageParser::Float))) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

testLanguageParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

testLanguageParser::ExpressionContext* testLanguageParser::StatementContext::expression() {
  return getRuleContext<testLanguageParser::ExpressionContext>(0);
}

testLanguageParser::DeclarationContext* testLanguageParser::StatementContext::declaration() {
  return getRuleContext<testLanguageParser::DeclarationContext>(0);
}

testLanguageParser::AssignmentContext* testLanguageParser::StatementContext::assignment() {
  return getRuleContext<testLanguageParser::AssignmentContext>(0);
}

testLanguageParser::ForStatementContext* testLanguageParser::StatementContext::forStatement() {
  return getRuleContext<testLanguageParser::ForStatementContext>(0);
}

testLanguageParser::IfStatementContext* testLanguageParser::StatementContext::ifStatement() {
  return getRuleContext<testLanguageParser::IfStatementContext>(0);
}


size_t testLanguageParser::StatementContext::getRuleIndex() const {
  return testLanguageParser::RuleStatement;
}

void testLanguageParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void testLanguageParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}

testLanguageParser::StatementContext* testLanguageParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 2, testLanguageParser::RuleStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(61);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(54);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << testLanguageParser::T__4)
        | (1ULL << testLanguageParser::Minus)
        | (1ULL << testLanguageParser::Negation)
        | (1ULL << testLanguageParser::Type)
        | (1ULL << testLanguageParser::Id)
        | (1ULL << testLanguageParser::Integer)
        | (1ULL << testLanguageParser::Float))) != 0)) {
        setState(53);
        expression(0);
      }
      setState(56);
      match(testLanguageParser::T__0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(57);
      declaration();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(58);
      assignment();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(59);
      forStatement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(60);
      ifStatement();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Defer_statementContext ------------------------------------------------------------------

testLanguageParser::Defer_statementContext::Defer_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* testLanguageParser::Defer_statementContext::Defer() {
  return getToken(testLanguageParser::Defer, 0);
}

testLanguageParser::StatementContext* testLanguageParser::Defer_statementContext::statement() {
  return getRuleContext<testLanguageParser::StatementContext>(0);
}


size_t testLanguageParser::Defer_statementContext::getRuleIndex() const {
  return testLanguageParser::RuleDefer_statement;
}

void testLanguageParser::Defer_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDefer_statement(this);
}

void testLanguageParser::Defer_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDefer_statement(this);
}

testLanguageParser::Defer_statementContext* testLanguageParser::defer_statement() {
  Defer_statementContext *_localctx = _tracker.createInstance<Defer_statementContext>(_ctx, getState());
  enterRule(_localctx, 4, testLanguageParser::RuleDefer_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(63);
    match(testLanguageParser::Defer);
    setState(64);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

testLanguageParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

testLanguageParser::Variable_typeContext* testLanguageParser::TypeContext::variable_type() {
  return getRuleContext<testLanguageParser::Variable_typeContext>(0);
}

testLanguageParser::Function_typeContext* testLanguageParser::TypeContext::function_type() {
  return getRuleContext<testLanguageParser::Function_typeContext>(0);
}


size_t testLanguageParser::TypeContext::getRuleIndex() const {
  return testLanguageParser::RuleType;
}

void testLanguageParser::TypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType(this);
}

void testLanguageParser::TypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType(this);
}

testLanguageParser::TypeContext* testLanguageParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 6, testLanguageParser::RuleType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(68);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(66);
      variable_type();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(67);
      function_type();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Formal_parameterContext ------------------------------------------------------------------

testLanguageParser::Formal_parameterContext::Formal_parameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* testLanguageParser::Formal_parameterContext::Id() {
  return getToken(testLanguageParser::Id, 0);
}

testLanguageParser::Variable_typeContext* testLanguageParser::Formal_parameterContext::variable_type() {
  return getRuleContext<testLanguageParser::Variable_typeContext>(0);
}

tree::TerminalNode* testLanguageParser::Formal_parameterContext::Var() {
  return getToken(testLanguageParser::Var, 0);
}

testLanguageParser::Function_typeContext* testLanguageParser::Formal_parameterContext::function_type() {
  return getRuleContext<testLanguageParser::Function_typeContext>(0);
}


size_t testLanguageParser::Formal_parameterContext::getRuleIndex() const {
  return testLanguageParser::RuleFormal_parameter;
}

void testLanguageParser::Formal_parameterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFormal_parameter(this);
}

void testLanguageParser::Formal_parameterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFormal_parameter(this);
}

testLanguageParser::Formal_parameterContext* testLanguageParser::formal_parameter() {
  Formal_parameterContext *_localctx = _tracker.createInstance<Formal_parameterContext>(_ctx, getState());
  enterRule(_localctx, 8, testLanguageParser::RuleFormal_parameter);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(76);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case testLanguageParser::Var:
      case testLanguageParser::Id: {
        enterOuterAlt(_localctx, 1);
        setState(71);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == testLanguageParser::Var) {
          setState(70);
          match(testLanguageParser::Var);
        }
        setState(73);
        match(testLanguageParser::Id);
        setState(74);
        variable_type();
        break;
      }

      case testLanguageParser::T__4:
      case testLanguageParser::Type: {
        enterOuterAlt(_localctx, 2);
        setState(75);
        function_type();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Formal_parameter_listContext ------------------------------------------------------------------

testLanguageParser::Formal_parameter_listContext::Formal_parameter_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<testLanguageParser::Formal_parameterContext *> testLanguageParser::Formal_parameter_listContext::formal_parameter() {
  return getRuleContexts<testLanguageParser::Formal_parameterContext>();
}

testLanguageParser::Formal_parameterContext* testLanguageParser::Formal_parameter_listContext::formal_parameter(size_t i) {
  return getRuleContext<testLanguageParser::Formal_parameterContext>(i);
}


size_t testLanguageParser::Formal_parameter_listContext::getRuleIndex() const {
  return testLanguageParser::RuleFormal_parameter_list;
}

void testLanguageParser::Formal_parameter_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFormal_parameter_list(this);
}

void testLanguageParser::Formal_parameter_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFormal_parameter_list(this);
}

testLanguageParser::Formal_parameter_listContext* testLanguageParser::formal_parameter_list() {
  Formal_parameter_listContext *_localctx = _tracker.createInstance<Formal_parameter_listContext>(_ctx, getState());
  enterRule(_localctx, 10, testLanguageParser::RuleFormal_parameter_list);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(79);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << testLanguageParser::T__4)
      | (1ULL << testLanguageParser::Var)
      | (1ULL << testLanguageParser::Type)
      | (1ULL << testLanguageParser::Id))) != 0)) {
      setState(78);
      formal_parameter();
    }
    setState(85);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == testLanguageParser::T__1) {
      setState(81);
      match(testLanguageParser::T__1);
      setState(82);
      formal_parameter();
      setState(87);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Variable_typeContext ------------------------------------------------------------------

testLanguageParser::Variable_typeContext::Variable_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* testLanguageParser::Variable_typeContext::Type() {
  return getToken(testLanguageParser::Type, 0);
}

tree::TerminalNode* testLanguageParser::Variable_typeContext::Integer() {
  return getToken(testLanguageParser::Integer, 0);
}


size_t testLanguageParser::Variable_typeContext::getRuleIndex() const {
  return testLanguageParser::RuleVariable_type;
}

void testLanguageParser::Variable_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable_type(this);
}

void testLanguageParser::Variable_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable_type(this);
}

testLanguageParser::Variable_typeContext* testLanguageParser::variable_type() {
  Variable_typeContext *_localctx = _tracker.createInstance<Variable_typeContext>(_ctx, getState());
  enterRule(_localctx, 12, testLanguageParser::RuleVariable_type);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(88);
    match(testLanguageParser::Type);
    setState(92);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == testLanguageParser::T__2) {
      setState(89);
      match(testLanguageParser::T__2);
      setState(90);
      match(testLanguageParser::Integer);
      setState(91);
      match(testLanguageParser::T__3);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_typeContext ------------------------------------------------------------------

testLanguageParser::Function_typeContext::Function_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<testLanguageParser::Formal_parameter_listContext *> testLanguageParser::Function_typeContext::formal_parameter_list() {
  return getRuleContexts<testLanguageParser::Formal_parameter_listContext>();
}

testLanguageParser::Formal_parameter_listContext* testLanguageParser::Function_typeContext::formal_parameter_list(size_t i) {
  return getRuleContext<testLanguageParser::Formal_parameter_listContext>(i);
}

tree::TerminalNode* testLanguageParser::Function_typeContext::Type() {
  return getToken(testLanguageParser::Type, 0);
}


size_t testLanguageParser::Function_typeContext::getRuleIndex() const {
  return testLanguageParser::RuleFunction_type;
}

void testLanguageParser::Function_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction_type(this);
}

void testLanguageParser::Function_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction_type(this);
}

testLanguageParser::Function_typeContext* testLanguageParser::function_type() {
  Function_typeContext *_localctx = _tracker.createInstance<Function_typeContext>(_ctx, getState());
  enterRule(_localctx, 14, testLanguageParser::RuleFunction_type);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(103);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case testLanguageParser::T__4: {
        enterOuterAlt(_localctx, 1);
        setState(94);
        match(testLanguageParser::T__4);
        setState(95);
        formal_parameter_list();
        setState(96);
        match(testLanguageParser::T__5);
        setState(97);
        match(testLanguageParser::T__6);
        setState(98);
        match(testLanguageParser::T__4);
        setState(99);
        formal_parameter_list();
        setState(100);
        match(testLanguageParser::T__5);
        break;
      }

      case testLanguageParser::Type: {
        enterOuterAlt(_localctx, 2);
        setState(102);
        match(testLanguageParser::Type);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Id_declarationContext ------------------------------------------------------------------

testLanguageParser::Id_declarationContext::Id_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> testLanguageParser::Id_declarationContext::Id() {
  return getTokens(testLanguageParser::Id);
}

tree::TerminalNode* testLanguageParser::Id_declarationContext::Id(size_t i) {
  return getToken(testLanguageParser::Id, i);
}

testLanguageParser::Variable_typeContext* testLanguageParser::Id_declarationContext::variable_type() {
  return getRuleContext<testLanguageParser::Variable_typeContext>(0);
}

std::vector<testLanguageParser::ExpressionContext *> testLanguageParser::Id_declarationContext::expression() {
  return getRuleContexts<testLanguageParser::ExpressionContext>();
}

testLanguageParser::ExpressionContext* testLanguageParser::Id_declarationContext::expression(size_t i) {
  return getRuleContext<testLanguageParser::ExpressionContext>(i);
}


size_t testLanguageParser::Id_declarationContext::getRuleIndex() const {
  return testLanguageParser::RuleId_declaration;
}

void testLanguageParser::Id_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterId_declaration(this);
}

void testLanguageParser::Id_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitId_declaration(this);
}

testLanguageParser::Id_declarationContext* testLanguageParser::id_declaration() {
  Id_declarationContext *_localctx = _tracker.createInstance<Id_declarationContext>(_ctx, getState());
  enterRule(_localctx, 16, testLanguageParser::RuleId_declaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(105);
    match(testLanguageParser::Id);
    setState(110);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == testLanguageParser::T__1) {
      setState(106);
      match(testLanguageParser::T__1);
      setState(107);
      match(testLanguageParser::Id);
      setState(112);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(113);
    variable_type();
    setState(123);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == testLanguageParser::T__7) {
      setState(114);
      match(testLanguageParser::T__7);
      setState(115);
      expression(0);
      setState(120);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == testLanguageParser::T__1) {
        setState(116);
        match(testLanguageParser::T__1);
        setState(117);
        expression(0);
        setState(122);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(125);
    match(testLanguageParser::T__0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_declarationContext ------------------------------------------------------------------

testLanguageParser::Function_declarationContext::Function_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* testLanguageParser::Function_declarationContext::Func() {
  return getToken(testLanguageParser::Func, 0);
}

tree::TerminalNode* testLanguageParser::Function_declarationContext::Id() {
  return getToken(testLanguageParser::Id, 0);
}

testLanguageParser::Function_typeContext* testLanguageParser::Function_declarationContext::function_type() {
  return getRuleContext<testLanguageParser::Function_typeContext>(0);
}

testLanguageParser::ScopeBlockContext* testLanguageParser::Function_declarationContext::scopeBlock() {
  return getRuleContext<testLanguageParser::ScopeBlockContext>(0);
}


size_t testLanguageParser::Function_declarationContext::getRuleIndex() const {
  return testLanguageParser::RuleFunction_declaration;
}

void testLanguageParser::Function_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction_declaration(this);
}

void testLanguageParser::Function_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction_declaration(this);
}

testLanguageParser::Function_declarationContext* testLanguageParser::function_declaration() {
  Function_declarationContext *_localctx = _tracker.createInstance<Function_declarationContext>(_ctx, getState());
  enterRule(_localctx, 18, testLanguageParser::RuleFunction_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(127);
    match(testLanguageParser::Func);
    setState(128);
    match(testLanguageParser::Id);
    setState(129);
    function_type();
    setState(130);
    scopeBlock();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Variable_type_declarationContext ------------------------------------------------------------------

testLanguageParser::Variable_type_declarationContext::Variable_type_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* testLanguageParser::Variable_type_declarationContext::Type() {
  return getToken(testLanguageParser::Type, 0);
}

std::vector<testLanguageParser::Variable_typeContext *> testLanguageParser::Variable_type_declarationContext::variable_type() {
  return getRuleContexts<testLanguageParser::Variable_typeContext>();
}

testLanguageParser::Variable_typeContext* testLanguageParser::Variable_type_declarationContext::variable_type(size_t i) {
  return getRuleContext<testLanguageParser::Variable_typeContext>(i);
}

std::vector<tree::TerminalNode *> testLanguageParser::Variable_type_declarationContext::Id() {
  return getTokens(testLanguageParser::Id);
}

tree::TerminalNode* testLanguageParser::Variable_type_declarationContext::Id(size_t i) {
  return getToken(testLanguageParser::Id, i);
}


size_t testLanguageParser::Variable_type_declarationContext::getRuleIndex() const {
  return testLanguageParser::RuleVariable_type_declaration;
}

void testLanguageParser::Variable_type_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable_type_declaration(this);
}

void testLanguageParser::Variable_type_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable_type_declaration(this);
}

testLanguageParser::Variable_type_declarationContext* testLanguageParser::variable_type_declaration() {
  Variable_type_declarationContext *_localctx = _tracker.createInstance<Variable_type_declarationContext>(_ctx, getState());
  enterRule(_localctx, 20, testLanguageParser::RuleVariable_type_declaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(132);
    match(testLanguageParser::T__8);
    setState(133);
    match(testLanguageParser::Type);
    setState(134);
    match(testLanguageParser::T__7);
    setState(148);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case testLanguageParser::Type: {
        setState(135);
        variable_type();
        break;
      }

      case testLanguageParser::T__9: {
        setState(136);
        match(testLanguageParser::T__9);
        setState(137);
        match(testLanguageParser::Id);
        setState(138);
        variable_type();
        setState(142); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(139);
          match(testLanguageParser::T__1);
          setState(140);
          match(testLanguageParser::Id);
          setState(141);
          variable_type();
          setState(144); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == testLanguageParser::T__1);
        setState(146);
        match(testLanguageParser::T__10);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(150);
    match(testLanguageParser::T__0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_type_declarationContext ------------------------------------------------------------------

testLanguageParser::Function_type_declarationContext::Function_type_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* testLanguageParser::Function_type_declarationContext::Type() {
  return getToken(testLanguageParser::Type, 0);
}

testLanguageParser::Function_typeContext* testLanguageParser::Function_type_declarationContext::function_type() {
  return getRuleContext<testLanguageParser::Function_typeContext>(0);
}


size_t testLanguageParser::Function_type_declarationContext::getRuleIndex() const {
  return testLanguageParser::RuleFunction_type_declaration;
}

void testLanguageParser::Function_type_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction_type_declaration(this);
}

void testLanguageParser::Function_type_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction_type_declaration(this);
}

testLanguageParser::Function_type_declarationContext* testLanguageParser::function_type_declaration() {
  Function_type_declarationContext *_localctx = _tracker.createInstance<Function_type_declarationContext>(_ctx, getState());
  enterRule(_localctx, 22, testLanguageParser::RuleFunction_type_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(152);
    match(testLanguageParser::T__8);
    setState(153);
    match(testLanguageParser::Type);
    setState(154);
    match(testLanguageParser::T__7);
    setState(155);
    function_type();
    setState(156);
    match(testLanguageParser::T__0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_declarationContext ------------------------------------------------------------------

testLanguageParser::Type_declarationContext::Type_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

testLanguageParser::Variable_type_declarationContext* testLanguageParser::Type_declarationContext::variable_type_declaration() {
  return getRuleContext<testLanguageParser::Variable_type_declarationContext>(0);
}

testLanguageParser::Function_type_declarationContext* testLanguageParser::Type_declarationContext::function_type_declaration() {
  return getRuleContext<testLanguageParser::Function_type_declarationContext>(0);
}


size_t testLanguageParser::Type_declarationContext::getRuleIndex() const {
  return testLanguageParser::RuleType_declaration;
}

void testLanguageParser::Type_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_declaration(this);
}

void testLanguageParser::Type_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_declaration(this);
}

testLanguageParser::Type_declarationContext* testLanguageParser::type_declaration() {
  Type_declarationContext *_localctx = _tracker.createInstance<Type_declarationContext>(_ctx, getState());
  enterRule(_localctx, 24, testLanguageParser::RuleType_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(160);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(158);
      variable_type_declaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(159);
      function_type_declaration();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationContext ------------------------------------------------------------------

testLanguageParser::DeclarationContext::DeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

testLanguageParser::Id_declarationContext* testLanguageParser::DeclarationContext::id_declaration() {
  return getRuleContext<testLanguageParser::Id_declarationContext>(0);
}

testLanguageParser::Function_declarationContext* testLanguageParser::DeclarationContext::function_declaration() {
  return getRuleContext<testLanguageParser::Function_declarationContext>(0);
}

testLanguageParser::Type_declarationContext* testLanguageParser::DeclarationContext::type_declaration() {
  return getRuleContext<testLanguageParser::Type_declarationContext>(0);
}


size_t testLanguageParser::DeclarationContext::getRuleIndex() const {
  return testLanguageParser::RuleDeclaration;
}

void testLanguageParser::DeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration(this);
}

void testLanguageParser::DeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration(this);
}

testLanguageParser::DeclarationContext* testLanguageParser::declaration() {
  DeclarationContext *_localctx = _tracker.createInstance<DeclarationContext>(_ctx, getState());
  enterRule(_localctx, 26, testLanguageParser::RuleDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(165);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case testLanguageParser::Id: {
        enterOuterAlt(_localctx, 1);
        setState(162);
        id_declaration();
        break;
      }

      case testLanguageParser::Func: {
        enterOuterAlt(_localctx, 2);
        setState(163);
        function_declaration();
        break;
      }

      case testLanguageParser::T__8: {
        enterOuterAlt(_localctx, 3);
        setState(164);
        type_declaration();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Member_accessContext ------------------------------------------------------------------

testLanguageParser::Member_accessContext::Member_accessContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> testLanguageParser::Member_accessContext::Id() {
  return getTokens(testLanguageParser::Id);
}

tree::TerminalNode* testLanguageParser::Member_accessContext::Id(size_t i) {
  return getToken(testLanguageParser::Id, i);
}


size_t testLanguageParser::Member_accessContext::getRuleIndex() const {
  return testLanguageParser::RuleMember_access;
}

void testLanguageParser::Member_accessContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMember_access(this);
}

void testLanguageParser::Member_accessContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMember_access(this);
}

testLanguageParser::Member_accessContext* testLanguageParser::member_access() {
  Member_accessContext *_localctx = _tracker.createInstance<Member_accessContext>(_ctx, getState());
  enterRule(_localctx, 28, testLanguageParser::RuleMember_access);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(167);
    match(testLanguageParser::Id);
    setState(168);
    match(testLanguageParser::T__11);
    setState(169);
    match(testLanguageParser::Id);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentContext ------------------------------------------------------------------

testLanguageParser::AssignmentContext::AssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> testLanguageParser::AssignmentContext::Id() {
  return getTokens(testLanguageParser::Id);
}

tree::TerminalNode* testLanguageParser::AssignmentContext::Id(size_t i) {
  return getToken(testLanguageParser::Id, i);
}

std::vector<testLanguageParser::ExpressionContext *> testLanguageParser::AssignmentContext::expression() {
  return getRuleContexts<testLanguageParser::ExpressionContext>();
}

testLanguageParser::ExpressionContext* testLanguageParser::AssignmentContext::expression(size_t i) {
  return getRuleContext<testLanguageParser::ExpressionContext>(i);
}

std::vector<testLanguageParser::Member_accessContext *> testLanguageParser::AssignmentContext::member_access() {
  return getRuleContexts<testLanguageParser::Member_accessContext>();
}

testLanguageParser::Member_accessContext* testLanguageParser::AssignmentContext::member_access(size_t i) {
  return getRuleContext<testLanguageParser::Member_accessContext>(i);
}


size_t testLanguageParser::AssignmentContext::getRuleIndex() const {
  return testLanguageParser::RuleAssignment;
}

void testLanguageParser::AssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignment(this);
}

void testLanguageParser::AssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignment(this);
}

testLanguageParser::AssignmentContext* testLanguageParser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 30, testLanguageParser::RuleAssignment);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(198);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(171);
      match(testLanguageParser::Id);
      setState(176);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == testLanguageParser::T__1) {
        setState(172);
        match(testLanguageParser::T__1);
        setState(173);
        match(testLanguageParser::Id);
        setState(178);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(179);
      member_access();
      setState(184);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == testLanguageParser::T__1) {
        setState(180);
        match(testLanguageParser::T__1);
        setState(181);
        member_access();
        setState(186);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(187);
      match(testLanguageParser::T__7);
      setState(188);
      expression(0);
      setState(193);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == testLanguageParser::T__1) {
        setState(189);
        match(testLanguageParser::T__1);
        setState(190);
        expression(0);
        setState(195);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(196);
      match(testLanguageParser::T__0);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

testLanguageParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t testLanguageParser::ExpressionContext::getRuleIndex() const {
  return testLanguageParser::RuleExpression;
}

void testLanguageParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Constant_integer_expressionContext ------------------------------------------------------------------

tree::TerminalNode* testLanguageParser::Constant_integer_expressionContext::Integer() {
  return getToken(testLanguageParser::Integer, 0);
}

testLanguageParser::Constant_integer_expressionContext::Constant_integer_expressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

void testLanguageParser::Constant_integer_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstant_integer_expression(this);
}
void testLanguageParser::Constant_integer_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstant_integer_expression(this);
}
//----------------- Function_callContext ------------------------------------------------------------------

tree::TerminalNode* testLanguageParser::Function_callContext::Id() {
  return getToken(testLanguageParser::Id, 0);
}

std::vector<testLanguageParser::ExpressionContext *> testLanguageParser::Function_callContext::expression() {
  return getRuleContexts<testLanguageParser::ExpressionContext>();
}

testLanguageParser::ExpressionContext* testLanguageParser::Function_callContext::expression(size_t i) {
  return getRuleContext<testLanguageParser::ExpressionContext>(i);
}

testLanguageParser::Function_callContext::Function_callContext(ExpressionContext *ctx) { copyFrom(ctx); }

void testLanguageParser::Function_callContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction_call(this);
}
void testLanguageParser::Function_callContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction_call(this);
}
//----------------- Constant_float_expressionContext ------------------------------------------------------------------

tree::TerminalNode* testLanguageParser::Constant_float_expressionContext::Float() {
  return getToken(testLanguageParser::Float, 0);
}

testLanguageParser::Constant_float_expressionContext::Constant_float_expressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

void testLanguageParser::Constant_float_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstant_float_expression(this);
}
void testLanguageParser::Constant_float_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstant_float_expression(this);
}
//----------------- Init_expressionContext ------------------------------------------------------------------

testLanguageParser::Variable_typeContext* testLanguageParser::Init_expressionContext::variable_type() {
  return getRuleContext<testLanguageParser::Variable_typeContext>(0);
}

std::vector<testLanguageParser::ExpressionContext *> testLanguageParser::Init_expressionContext::expression() {
  return getRuleContexts<testLanguageParser::ExpressionContext>();
}

testLanguageParser::ExpressionContext* testLanguageParser::Init_expressionContext::expression(size_t i) {
  return getRuleContext<testLanguageParser::ExpressionContext>(i);
}

testLanguageParser::Init_expressionContext::Init_expressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

void testLanguageParser::Init_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInit_expression(this);
}
void testLanguageParser::Init_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInit_expression(this);
}
//----------------- Multiply_expressionContext ------------------------------------------------------------------

std::vector<testLanguageParser::ExpressionContext *> testLanguageParser::Multiply_expressionContext::expression() {
  return getRuleContexts<testLanguageParser::ExpressionContext>();
}

testLanguageParser::ExpressionContext* testLanguageParser::Multiply_expressionContext::expression(size_t i) {
  return getRuleContext<testLanguageParser::ExpressionContext>(i);
}

tree::TerminalNode* testLanguageParser::Multiply_expressionContext::Star() {
  return getToken(testLanguageParser::Star, 0);
}

tree::TerminalNode* testLanguageParser::Multiply_expressionContext::Slash() {
  return getToken(testLanguageParser::Slash, 0);
}

testLanguageParser::Multiply_expressionContext::Multiply_expressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

void testLanguageParser::Multiply_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiply_expression(this);
}
void testLanguageParser::Multiply_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiply_expression(this);
}
//----------------- Sum_expressionContext ------------------------------------------------------------------

std::vector<testLanguageParser::ExpressionContext *> testLanguageParser::Sum_expressionContext::expression() {
  return getRuleContexts<testLanguageParser::ExpressionContext>();
}

testLanguageParser::ExpressionContext* testLanguageParser::Sum_expressionContext::expression(size_t i) {
  return getRuleContext<testLanguageParser::ExpressionContext>(i);
}

tree::TerminalNode* testLanguageParser::Sum_expressionContext::Plus() {
  return getToken(testLanguageParser::Plus, 0);
}

tree::TerminalNode* testLanguageParser::Sum_expressionContext::Minus() {
  return getToken(testLanguageParser::Minus, 0);
}

testLanguageParser::Sum_expressionContext::Sum_expressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

void testLanguageParser::Sum_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSum_expression(this);
}
void testLanguageParser::Sum_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSum_expression(this);
}
//----------------- Comparison_expressionContext ------------------------------------------------------------------

std::vector<testLanguageParser::ExpressionContext *> testLanguageParser::Comparison_expressionContext::expression() {
  return getRuleContexts<testLanguageParser::ExpressionContext>();
}

testLanguageParser::ExpressionContext* testLanguageParser::Comparison_expressionContext::expression(size_t i) {
  return getRuleContext<testLanguageParser::ExpressionContext>(i);
}

tree::TerminalNode* testLanguageParser::Comparison_expressionContext::LessOrEqual() {
  return getToken(testLanguageParser::LessOrEqual, 0);
}

tree::TerminalNode* testLanguageParser::Comparison_expressionContext::Less() {
  return getToken(testLanguageParser::Less, 0);
}

tree::TerminalNode* testLanguageParser::Comparison_expressionContext::GreaterOrEqual() {
  return getToken(testLanguageParser::GreaterOrEqual, 0);
}

tree::TerminalNode* testLanguageParser::Comparison_expressionContext::Greater() {
  return getToken(testLanguageParser::Greater, 0);
}

tree::TerminalNode* testLanguageParser::Comparison_expressionContext::Equal() {
  return getToken(testLanguageParser::Equal, 0);
}

tree::TerminalNode* testLanguageParser::Comparison_expressionContext::NotEqual() {
  return getToken(testLanguageParser::NotEqual, 0);
}

testLanguageParser::Comparison_expressionContext::Comparison_expressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

void testLanguageParser::Comparison_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComparison_expression(this);
}
void testLanguageParser::Comparison_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComparison_expression(this);
}
//----------------- Variable_expressionContext ------------------------------------------------------------------

tree::TerminalNode* testLanguageParser::Variable_expressionContext::Id() {
  return getToken(testLanguageParser::Id, 0);
}

testLanguageParser::Variable_expressionContext::Variable_expressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

void testLanguageParser::Variable_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable_expression(this);
}
void testLanguageParser::Variable_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable_expression(this);
}
//----------------- Invert_sign_expressionContext ------------------------------------------------------------------

tree::TerminalNode* testLanguageParser::Invert_sign_expressionContext::Minus() {
  return getToken(testLanguageParser::Minus, 0);
}

testLanguageParser::ExpressionContext* testLanguageParser::Invert_sign_expressionContext::expression() {
  return getRuleContext<testLanguageParser::ExpressionContext>(0);
}

testLanguageParser::Invert_sign_expressionContext::Invert_sign_expressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

void testLanguageParser::Invert_sign_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInvert_sign_expression(this);
}
void testLanguageParser::Invert_sign_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInvert_sign_expression(this);
}
//----------------- Negation_expressionContext ------------------------------------------------------------------

tree::TerminalNode* testLanguageParser::Negation_expressionContext::Negation() {
  return getToken(testLanguageParser::Negation, 0);
}

testLanguageParser::ExpressionContext* testLanguageParser::Negation_expressionContext::expression() {
  return getRuleContext<testLanguageParser::ExpressionContext>(0);
}

testLanguageParser::Negation_expressionContext::Negation_expressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

void testLanguageParser::Negation_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNegation_expression(this);
}
void testLanguageParser::Negation_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNegation_expression(this);
}
//----------------- Parenthesized_expressionContext ------------------------------------------------------------------

testLanguageParser::ExpressionContext* testLanguageParser::Parenthesized_expressionContext::expression() {
  return getRuleContext<testLanguageParser::ExpressionContext>(0);
}

testLanguageParser::Parenthesized_expressionContext::Parenthesized_expressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

void testLanguageParser::Parenthesized_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParenthesized_expression(this);
}
void testLanguageParser::Parenthesized_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParenthesized_expression(this);
}
//----------------- Member_access_expressionContext ------------------------------------------------------------------

testLanguageParser::Member_accessContext* testLanguageParser::Member_access_expressionContext::member_access() {
  return getRuleContext<testLanguageParser::Member_accessContext>(0);
}

testLanguageParser::Member_access_expressionContext::Member_access_expressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

void testLanguageParser::Member_access_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMember_access_expression(this);
}
void testLanguageParser::Member_access_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMember_access_expression(this);
}
//----------------- Logical_expressionContext ------------------------------------------------------------------

std::vector<testLanguageParser::ExpressionContext *> testLanguageParser::Logical_expressionContext::expression() {
  return getRuleContexts<testLanguageParser::ExpressionContext>();
}

testLanguageParser::ExpressionContext* testLanguageParser::Logical_expressionContext::expression(size_t i) {
  return getRuleContext<testLanguageParser::ExpressionContext>(i);
}

tree::TerminalNode* testLanguageParser::Logical_expressionContext::Or() {
  return getToken(testLanguageParser::Or, 0);
}

tree::TerminalNode* testLanguageParser::Logical_expressionContext::And() {
  return getToken(testLanguageParser::And, 0);
}

tree::TerminalNode* testLanguageParser::Logical_expressionContext::Xor() {
  return getToken(testLanguageParser::Xor, 0);
}

testLanguageParser::Logical_expressionContext::Logical_expressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

void testLanguageParser::Logical_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogical_expression(this);
}
void testLanguageParser::Logical_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogical_expression(this);
}

testLanguageParser::ExpressionContext* testLanguageParser::expression() {
   return expression(0);
}

testLanguageParser::ExpressionContext* testLanguageParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  testLanguageParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  testLanguageParser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 32;
  enterRecursionRule(_localctx, 32, testLanguageParser::RuleExpression, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(238);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<Member_access_expressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(201);
      member_access();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<Invert_sign_expressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(202);
      match(testLanguageParser::Minus);
      setState(203);
      expression(10);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<Negation_expressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(204);
      match(testLanguageParser::Negation);
      setState(205);
      expression(9);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<Variable_expressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(206);
      match(testLanguageParser::Id);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<Constant_integer_expressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(207);
      match(testLanguageParser::Integer);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<Constant_float_expressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(208);
      match(testLanguageParser::Float);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<Init_expressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(209);
      variable_type();
      setState(210);
      match(testLanguageParser::T__9);
      setState(211);
      expression(0);
      setState(216);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == testLanguageParser::T__1) {
        setState(212);
        match(testLanguageParser::T__1);
        setState(213);
        expression(0);
        setState(218);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(219);
      match(testLanguageParser::T__10);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<Function_callContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(221);
      match(testLanguageParser::Id);
      setState(222);
      match(testLanguageParser::T__4);
      setState(224);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << testLanguageParser::T__4)
        | (1ULL << testLanguageParser::Minus)
        | (1ULL << testLanguageParser::Negation)
        | (1ULL << testLanguageParser::Type)
        | (1ULL << testLanguageParser::Id)
        | (1ULL << testLanguageParser::Integer)
        | (1ULL << testLanguageParser::Float))) != 0)) {
        setState(223);
        expression(0);
      }
      setState(230);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == testLanguageParser::T__1) {
        setState(226);
        match(testLanguageParser::T__1);
        setState(227);
        expression(0);
        setState(232);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(233);
      match(testLanguageParser::T__5);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<Parenthesized_expressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(234);
      match(testLanguageParser::T__4);
      setState(235);
      expression(0);
      setState(236);
      match(testLanguageParser::T__5);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(254);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(252);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<Multiply_expressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(240);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(241);
          _la = _input->LA(1);
          if (!(_la == testLanguageParser::Slash

          || _la == testLanguageParser::Star)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(242);
          expression(13);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<Sum_expressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(243);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(244);
          _la = _input->LA(1);
          if (!(_la == testLanguageParser::Plus

          || _la == testLanguageParser::Minus)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(245);
          expression(12);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<Logical_expressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(246);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(247);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << testLanguageParser::Or)
            | (1ULL << testLanguageParser::And)
            | (1ULL << testLanguageParser::Xor))) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(248);
          expression(9);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<Comparison_expressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(249);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(250);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << testLanguageParser::LessOrEqual)
            | (1ULL << testLanguageParser::Less)
            | (1ULL << testLanguageParser::GreaterOrEqual)
            | (1ULL << testLanguageParser::Greater)
            | (1ULL << testLanguageParser::Equal)
            | (1ULL << testLanguageParser::NotEqual))) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(251);
          expression(8);
          break;
        }

        default:
          break;
        } 
      }
      setState(256);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ScopeBlockContext ------------------------------------------------------------------

testLanguageParser::ScopeBlockContext::ScopeBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<testLanguageParser::StatementContext *> testLanguageParser::ScopeBlockContext::statement() {
  return getRuleContexts<testLanguageParser::StatementContext>();
}

testLanguageParser::StatementContext* testLanguageParser::ScopeBlockContext::statement(size_t i) {
  return getRuleContext<testLanguageParser::StatementContext>(i);
}

std::vector<testLanguageParser::ScopeBlockContext *> testLanguageParser::ScopeBlockContext::scopeBlock() {
  return getRuleContexts<testLanguageParser::ScopeBlockContext>();
}

testLanguageParser::ScopeBlockContext* testLanguageParser::ScopeBlockContext::scopeBlock(size_t i) {
  return getRuleContext<testLanguageParser::ScopeBlockContext>(i);
}


size_t testLanguageParser::ScopeBlockContext::getRuleIndex() const {
  return testLanguageParser::RuleScopeBlock;
}

void testLanguageParser::ScopeBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterScopeBlock(this);
}

void testLanguageParser::ScopeBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitScopeBlock(this);
}

testLanguageParser::ScopeBlockContext* testLanguageParser::scopeBlock() {
  ScopeBlockContext *_localctx = _tracker.createInstance<ScopeBlockContext>(_ctx, getState());
  enterRule(_localctx, 34, testLanguageParser::RuleScopeBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(257);
    match(testLanguageParser::T__9);
    setState(262);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << testLanguageParser::T__0)
      | (1ULL << testLanguageParser::T__4)
      | (1ULL << testLanguageParser::T__8)
      | (1ULL << testLanguageParser::T__9)
      | (1ULL << testLanguageParser::Func)
      | (1ULL << testLanguageParser::If)
      | (1ULL << testLanguageParser::For)
      | (1ULL << testLanguageParser::Minus)
      | (1ULL << testLanguageParser::Negation)
      | (1ULL << testLanguageParser::Type)
      | (1ULL << testLanguageParser::Id)
      | (1ULL << testLanguageParser::Integer)
      | (1ULL << testLanguageParser::Float))) != 0)) {
      setState(260);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case testLanguageParser::T__0:
        case testLanguageParser::T__4:
        case testLanguageParser::T__8:
        case testLanguageParser::Func:
        case testLanguageParser::If:
        case testLanguageParser::For:
        case testLanguageParser::Minus:
        case testLanguageParser::Negation:
        case testLanguageParser::Type:
        case testLanguageParser::Id:
        case testLanguageParser::Integer:
        case testLanguageParser::Float: {
          setState(258);
          statement();
          break;
        }

        case testLanguageParser::T__9: {
          setState(259);
          scopeBlock();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(264);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(265);
    match(testLanguageParser::T__10);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForVariableContext ------------------------------------------------------------------

testLanguageParser::ForVariableContext::ForVariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* testLanguageParser::ForVariableContext::Id() {
  return getToken(testLanguageParser::Id, 0);
}


size_t testLanguageParser::ForVariableContext::getRuleIndex() const {
  return testLanguageParser::RuleForVariable;
}

void testLanguageParser::ForVariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForVariable(this);
}

void testLanguageParser::ForVariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForVariable(this);
}

testLanguageParser::ForVariableContext* testLanguageParser::forVariable() {
  ForVariableContext *_localctx = _tracker.createInstance<ForVariableContext>(_ctx, getState());
  enterRule(_localctx, 36, testLanguageParser::RuleForVariable);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(267);
    _la = _input->LA(1);
    if (!(_la == testLanguageParser::T__12

    || _la == testLanguageParser::Id)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ByClauseContext ------------------------------------------------------------------

testLanguageParser::ByClauseContext::ByClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* testLanguageParser::ByClauseContext::By() {
  return getToken(testLanguageParser::By, 0);
}

testLanguageParser::ExpressionContext* testLanguageParser::ByClauseContext::expression() {
  return getRuleContext<testLanguageParser::ExpressionContext>(0);
}


size_t testLanguageParser::ByClauseContext::getRuleIndex() const {
  return testLanguageParser::RuleByClause;
}

void testLanguageParser::ByClauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterByClause(this);
}

void testLanguageParser::ByClauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitByClause(this);
}

testLanguageParser::ByClauseContext* testLanguageParser::byClause() {
  ByClauseContext *_localctx = _tracker.createInstance<ByClauseContext>(_ctx, getState());
  enterRule(_localctx, 38, testLanguageParser::RuleByClause);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(269);
    match(testLanguageParser::By);
    setState(270);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RangeContext ------------------------------------------------------------------

testLanguageParser::RangeContext::RangeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* testLanguageParser::RangeContext::From() {
  return getToken(testLanguageParser::From, 0);
}

std::vector<testLanguageParser::ExpressionContext *> testLanguageParser::RangeContext::expression() {
  return getRuleContexts<testLanguageParser::ExpressionContext>();
}

testLanguageParser::ExpressionContext* testLanguageParser::RangeContext::expression(size_t i) {
  return getRuleContext<testLanguageParser::ExpressionContext>(i);
}

tree::TerminalNode* testLanguageParser::RangeContext::To() {
  return getToken(testLanguageParser::To, 0);
}


size_t testLanguageParser::RangeContext::getRuleIndex() const {
  return testLanguageParser::RuleRange;
}

void testLanguageParser::RangeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRange(this);
}

void testLanguageParser::RangeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRange(this);
}

testLanguageParser::RangeContext* testLanguageParser::range() {
  RangeContext *_localctx = _tracker.createInstance<RangeContext>(_ctx, getState());
  enterRule(_localctx, 40, testLanguageParser::RuleRange);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(272);
    match(testLanguageParser::From);
    setState(273);
    expression(0);
    setState(274);
    match(testLanguageParser::To);
    setState(275);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForStatementContext ------------------------------------------------------------------

testLanguageParser::ForStatementContext::ForStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* testLanguageParser::ForStatementContext::For() {
  return getToken(testLanguageParser::For, 0);
}

std::vector<testLanguageParser::ForVariableContext *> testLanguageParser::ForStatementContext::forVariable() {
  return getRuleContexts<testLanguageParser::ForVariableContext>();
}

testLanguageParser::ForVariableContext* testLanguageParser::ForStatementContext::forVariable(size_t i) {
  return getRuleContext<testLanguageParser::ForVariableContext>(i);
}

testLanguageParser::ScopeBlockContext* testLanguageParser::ForStatementContext::scopeBlock() {
  return getRuleContext<testLanguageParser::ScopeBlockContext>(0);
}

tree::TerminalNode* testLanguageParser::ForStatementContext::In() {
  return getToken(testLanguageParser::In, 0);
}

testLanguageParser::ExpressionContext* testLanguageParser::ForStatementContext::expression() {
  return getRuleContext<testLanguageParser::ExpressionContext>(0);
}

testLanguageParser::RangeContext* testLanguageParser::ForStatementContext::range() {
  return getRuleContext<testLanguageParser::RangeContext>(0);
}

testLanguageParser::ByClauseContext* testLanguageParser::ForStatementContext::byClause() {
  return getRuleContext<testLanguageParser::ByClauseContext>(0);
}

tree::TerminalNode* testLanguageParser::ForStatementContext::Reverse() {
  return getToken(testLanguageParser::Reverse, 0);
}


size_t testLanguageParser::ForStatementContext::getRuleIndex() const {
  return testLanguageParser::RuleForStatement;
}

void testLanguageParser::ForStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForStatement(this);
}

void testLanguageParser::ForStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForStatement(this);
}

testLanguageParser::ForStatementContext* testLanguageParser::forStatement() {
  ForStatementContext *_localctx = _tracker.createInstance<ForStatementContext>(_ctx, getState());
  enterRule(_localctx, 42, testLanguageParser::RuleForStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(277);
    match(testLanguageParser::For);
    setState(278);
    forVariable();
    setState(279);
    match(testLanguageParser::T__1);
    setState(280);
    forVariable();
    setState(290);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case testLanguageParser::In: {
        setState(281);
        match(testLanguageParser::In);
        setState(283);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == testLanguageParser::Reverse) {
          setState(282);
          match(testLanguageParser::Reverse);
        }
        setState(285);
        expression(0);
        break;
      }

      case testLanguageParser::From:
      case testLanguageParser::Reverse: {
        setState(287);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == testLanguageParser::Reverse) {
          setState(286);
          match(testLanguageParser::Reverse);
        }
        setState(289);
        range();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(293);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == testLanguageParser::By) {
      setState(292);
      byClause();
    }
    setState(295);
    scopeBlock();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfStatementContext ------------------------------------------------------------------

testLanguageParser::IfStatementContext::IfStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* testLanguageParser::IfStatementContext::If() {
  return getToken(testLanguageParser::If, 0);
}

testLanguageParser::ExpressionContext* testLanguageParser::IfStatementContext::expression() {
  return getRuleContext<testLanguageParser::ExpressionContext>(0);
}

tree::TerminalNode* testLanguageParser::IfStatementContext::Then() {
  return getToken(testLanguageParser::Then, 0);
}

std::vector<testLanguageParser::ScopeBlockContext *> testLanguageParser::IfStatementContext::scopeBlock() {
  return getRuleContexts<testLanguageParser::ScopeBlockContext>();
}

testLanguageParser::ScopeBlockContext* testLanguageParser::IfStatementContext::scopeBlock(size_t i) {
  return getRuleContext<testLanguageParser::ScopeBlockContext>(i);
}

tree::TerminalNode* testLanguageParser::IfStatementContext::Else() {
  return getToken(testLanguageParser::Else, 0);
}

testLanguageParser::IfStatementContext* testLanguageParser::IfStatementContext::ifStatement() {
  return getRuleContext<testLanguageParser::IfStatementContext>(0);
}


size_t testLanguageParser::IfStatementContext::getRuleIndex() const {
  return testLanguageParser::RuleIfStatement;
}

void testLanguageParser::IfStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfStatement(this);
}

void testLanguageParser::IfStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<testLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfStatement(this);
}

testLanguageParser::IfStatementContext* testLanguageParser::ifStatement() {
  IfStatementContext *_localctx = _tracker.createInstance<IfStatementContext>(_ctx, getState());
  enterRule(_localctx, 44, testLanguageParser::RuleIfStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(297);
    match(testLanguageParser::If);
    setState(298);
    expression(0);
    setState(299);
    match(testLanguageParser::Then);
    setState(300);
    scopeBlock();
    setState(306);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == testLanguageParser::Else) {
      setState(301);
      match(testLanguageParser::Else);
      setState(304);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case testLanguageParser::T__9: {
          setState(302);
          scopeBlock();
          break;
        }

        case testLanguageParser::If: {
          setState(303);
          ifStatement();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool testLanguageParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 16: return expressionSempred(antlrcpp::downCast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool testLanguageParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 12);
    case 1: return precpred(_ctx, 11);
    case 2: return precpred(_ctx, 8);
    case 3: return precpred(_ctx, 7);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> testLanguageParser::_decisionToDFA;
atn::PredictionContextCache testLanguageParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN testLanguageParser::_atn;
std::vector<uint16_t> testLanguageParser::_serializedATN;

std::vector<std::string> testLanguageParser::_ruleNames = {
  "program", "statement", "defer_statement", "type", "formal_parameter", 
  "formal_parameter_list", "variable_type", "function_type", "id_declaration", 
  "function_declaration", "variable_type_declaration", "function_type_declaration", 
  "type_declaration", "declaration", "member_access", "assignment", "expression", 
  "scopeBlock", "forVariable", "byClause", "range", "forStatement", "ifStatement"
};

std::vector<std::string> testLanguageParser::_literalNames = {
  "", "';'", "','", "'['", "']'", "'('", "')'", "'->'", "':='", "'Type'", 
  "'{'", "'}'", "'.'", "'_'", "", "", "'defer'", "'Func'", "'if'", "'then'", 
  "'else'", "'for'", "'from'", "'to'", "'in'", "'by'", "'reverse'", "'var'", 
  "'/'", "'*'", "'+'", "'-'", "'<='", "'<'", "'>='", "'>'", "'='", "'!='", 
  "'!'", "'|'", "'&'", "'^'"
};

std::vector<std::string> testLanguageParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "Whitespace", 
  "Newline", "Defer", "Func", "If", "Then", "Else", "For", "From", "To", 
  "In", "By", "Reverse", "Var", "Slash", "Star", "Plus", "Minus", "LessOrEqual", 
  "Less", "GreaterOrEqual", "Greater", "Equal", "NotEqual", "Negation", 
  "Or", "And", "Xor", "Type", "Id", "Integer", "Float"
};

dfa::Vocabulary testLanguageParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> testLanguageParser::_tokenNames;

testLanguageParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  static const uint16_t serializedATNSegment0[] = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
       0x3, 0x2f, 0x137, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 
       0x4, 0xb, 0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 
       0xe, 0x9, 0xe, 0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 
       0x9, 0x11, 0x4, 0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 
       0x9, 0x14, 0x4, 0x15, 0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 
       0x9, 0x17, 0x4, 0x18, 0x9, 0x18, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x6, 
       0x2, 0x34, 0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 0x35, 0x3, 0x3, 0x5, 0x3, 
       0x39, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
       0x5, 0x3, 0x40, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 
       0x3, 0x5, 0x5, 0x5, 0x47, 0xa, 0x5, 0x3, 0x6, 0x5, 0x6, 0x4a, 0xa, 
       0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x4f, 0xa, 0x6, 0x3, 
       0x7, 0x5, 0x7, 0x52, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0x56, 
       0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0x59, 0xb, 0x7, 0x3, 0x8, 0x3, 0x8, 
       0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x5f, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 
       0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
       0x9, 0x5, 0x9, 0x6a, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 
       0xa, 0x6f, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0x72, 0xb, 0xa, 0x3, 0xa, 
       0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0x79, 0xa, 0xa, 
       0xc, 0xa, 0xe, 0xa, 0x7c, 0xb, 0xa, 0x5, 0xa, 0x7e, 0xa, 0xa, 0x3, 
       0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
       0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
       0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x6, 0xc, 0x91, 0xa, 0xc, 0xd, 
       0xc, 0xe, 0xc, 0x92, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x97, 0xa, 0xc, 
       0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
       0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0xa3, 0xa, 0xe, 0x3, 
       0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0xa8, 0xa, 0xf, 0x3, 0x10, 0x3, 
       0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x7, 
       0x11, 0xb1, 0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 0xb4, 0xb, 0x11, 0x3, 
       0x11, 0x3, 0x11, 0x3, 0x11, 0x7, 0x11, 0xb9, 0xa, 0x11, 0xc, 0x11, 
       0xe, 0x11, 0xbc, 0xb, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
       0x11, 0x7, 0x11, 0xc2, 0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 0xc5, 0xb, 
       0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0xc9, 0xa, 0x11, 0x3, 0x12, 
       0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
       0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
       0x3, 0x12, 0x7, 0x12, 0xd9, 0xa, 0x12, 0xc, 0x12, 0xe, 0x12, 0xdc, 
       0xb, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
       0x5, 0x12, 0xe3, 0xa, 0x12, 0x3, 0x12, 0x3, 0x12, 0x7, 0x12, 0xe7, 
       0xa, 0x12, 0xc, 0x12, 0xe, 0x12, 0xea, 0xb, 0x12, 0x3, 0x12, 0x3, 
       0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0xf1, 0xa, 0x12, 
       0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
       0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
       0x7, 0x12, 0xff, 0xa, 0x12, 0xc, 0x12, 0xe, 0x12, 0x102, 0xb, 0x12, 
       0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x7, 0x13, 0x107, 0xa, 0x13, 0xc, 
       0x13, 0xe, 0x13, 0x10a, 0xb, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 
       0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 
       0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 
       0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x11e, 0xa, 0x17, 0x3, 
       0x17, 0x3, 0x17, 0x5, 0x17, 0x122, 0xa, 0x17, 0x3, 0x17, 0x5, 0x17, 
       0x125, 0xa, 0x17, 0x3, 0x17, 0x5, 0x17, 0x128, 0xa, 0x17, 0x3, 0x17, 
       0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 
       0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 0x133, 0xa, 0x18, 0x5, 0x18, 0x135, 
       0xa, 0x18, 0x3, 0x18, 0x2, 0x3, 0x22, 0x19, 0x2, 0x4, 0x6, 0x8, 0xa, 
       0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 
       0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x2, 0x7, 0x3, 0x2, 0x1e, 0x1f, 
       0x3, 0x2, 0x20, 0x21, 0x3, 0x2, 0x29, 0x2b, 0x3, 0x2, 0x22, 0x27, 
       0x4, 0x2, 0xf, 0xf, 0x2d, 0x2d, 0x2, 0x151, 0x2, 0x33, 0x3, 0x2, 
       0x2, 0x2, 0x4, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x6, 0x41, 0x3, 0x2, 0x2, 
       0x2, 0x8, 0x46, 0x3, 0x2, 0x2, 0x2, 0xa, 0x4e, 0x3, 0x2, 0x2, 0x2, 
       0xc, 0x51, 0x3, 0x2, 0x2, 0x2, 0xe, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x10, 
       0x69, 0x3, 0x2, 0x2, 0x2, 0x12, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x14, 0x81, 
       0x3, 0x2, 0x2, 0x2, 0x16, 0x86, 0x3, 0x2, 0x2, 0x2, 0x18, 0x9a, 0x3, 
       0x2, 0x2, 0x2, 0x1a, 0xa2, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xa7, 0x3, 0x2, 
       0x2, 0x2, 0x1e, 0xa9, 0x3, 0x2, 0x2, 0x2, 0x20, 0xc8, 0x3, 0x2, 0x2, 
       0x2, 0x22, 0xf0, 0x3, 0x2, 0x2, 0x2, 0x24, 0x103, 0x3, 0x2, 0x2, 
       0x2, 0x26, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x28, 0x10f, 0x3, 0x2, 0x2, 
       0x2, 0x2a, 0x112, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x117, 0x3, 0x2, 0x2, 
       0x2, 0x2e, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x30, 0x34, 0x5, 0x4, 0x3, 
       0x2, 0x31, 0x34, 0x5, 0x6, 0x4, 0x2, 0x32, 0x34, 0x5, 0x24, 0x13, 
       0x2, 0x33, 0x30, 0x3, 0x2, 0x2, 0x2, 0x33, 0x31, 0x3, 0x2, 0x2, 0x2, 
       0x33, 0x32, 0x3, 0x2, 0x2, 0x2, 0x34, 0x35, 0x3, 0x2, 0x2, 0x2, 0x35, 
       0x33, 0x3, 0x2, 0x2, 0x2, 0x35, 0x36, 0x3, 0x2, 0x2, 0x2, 0x36, 0x3, 
       0x3, 0x2, 0x2, 0x2, 0x37, 0x39, 0x5, 0x22, 0x12, 0x2, 0x38, 0x37, 
       0x3, 0x2, 0x2, 0x2, 0x38, 0x39, 0x3, 0x2, 0x2, 0x2, 0x39, 0x3a, 0x3, 
       0x2, 0x2, 0x2, 0x3a, 0x40, 0x7, 0x3, 0x2, 0x2, 0x3b, 0x40, 0x5, 0x1c, 
       0xf, 0x2, 0x3c, 0x40, 0x5, 0x20, 0x11, 0x2, 0x3d, 0x40, 0x5, 0x2c, 
       0x17, 0x2, 0x3e, 0x40, 0x5, 0x2e, 0x18, 0x2, 0x3f, 0x38, 0x3, 0x2, 
       0x2, 0x2, 0x3f, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x3c, 0x3, 0x2, 0x2, 
       0x2, 0x3f, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x3e, 0x3, 0x2, 0x2, 0x2, 
       0x40, 0x5, 0x3, 0x2, 0x2, 0x2, 0x41, 0x42, 0x7, 0x12, 0x2, 0x2, 0x42, 
       0x43, 0x5, 0x4, 0x3, 0x2, 0x43, 0x7, 0x3, 0x2, 0x2, 0x2, 0x44, 0x47, 
       0x5, 0xe, 0x8, 0x2, 0x45, 0x47, 0x5, 0x10, 0x9, 0x2, 0x46, 0x44, 
       0x3, 0x2, 0x2, 0x2, 0x46, 0x45, 0x3, 0x2, 0x2, 0x2, 0x47, 0x9, 0x3, 
       0x2, 0x2, 0x2, 0x48, 0x4a, 0x7, 0x1d, 0x2, 0x2, 0x49, 0x48, 0x3, 
       0x2, 0x2, 0x2, 0x49, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x4b, 0x3, 0x2, 
       0x2, 0x2, 0x4b, 0x4c, 0x7, 0x2d, 0x2, 0x2, 0x4c, 0x4f, 0x5, 0xe, 
       0x8, 0x2, 0x4d, 0x4f, 0x5, 0x10, 0x9, 0x2, 0x4e, 0x49, 0x3, 0x2, 
       0x2, 0x2, 0x4e, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x4f, 0xb, 0x3, 0x2, 0x2, 
       0x2, 0x50, 0x52, 0x5, 0xa, 0x6, 0x2, 0x51, 0x50, 0x3, 0x2, 0x2, 0x2, 
       0x51, 0x52, 0x3, 0x2, 0x2, 0x2, 0x52, 0x57, 0x3, 0x2, 0x2, 0x2, 0x53, 
       0x54, 0x7, 0x4, 0x2, 0x2, 0x54, 0x56, 0x5, 0xa, 0x6, 0x2, 0x55, 0x53, 
       0x3, 0x2, 0x2, 0x2, 0x56, 0x59, 0x3, 0x2, 0x2, 0x2, 0x57, 0x55, 0x3, 
       0x2, 0x2, 0x2, 0x57, 0x58, 0x3, 0x2, 0x2, 0x2, 0x58, 0xd, 0x3, 0x2, 
       0x2, 0x2, 0x59, 0x57, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x5e, 0x7, 0x2c, 
       0x2, 0x2, 0x5b, 0x5c, 0x7, 0x5, 0x2, 0x2, 0x5c, 0x5d, 0x7, 0x2e, 
       0x2, 0x2, 0x5d, 0x5f, 0x7, 0x6, 0x2, 0x2, 0x5e, 0x5b, 0x3, 0x2, 0x2, 
       0x2, 0x5e, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x5f, 0xf, 0x3, 0x2, 0x2, 0x2, 
       0x60, 0x61, 0x7, 0x7, 0x2, 0x2, 0x61, 0x62, 0x5, 0xc, 0x7, 0x2, 0x62, 
       0x63, 0x7, 0x8, 0x2, 0x2, 0x63, 0x64, 0x7, 0x9, 0x2, 0x2, 0x64, 0x65, 
       0x7, 0x7, 0x2, 0x2, 0x65, 0x66, 0x5, 0xc, 0x7, 0x2, 0x66, 0x67, 0x7, 
       0x8, 0x2, 0x2, 0x67, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x68, 0x6a, 0x7, 0x2c, 
       0x2, 0x2, 0x69, 0x60, 0x3, 0x2, 0x2, 0x2, 0x69, 0x68, 0x3, 0x2, 0x2, 
       0x2, 0x6a, 0x11, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x70, 0x7, 0x2d, 0x2, 
       0x2, 0x6c, 0x6d, 0x7, 0x4, 0x2, 0x2, 0x6d, 0x6f, 0x7, 0x2d, 0x2, 
       0x2, 0x6e, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x72, 0x3, 0x2, 0x2, 0x2, 
       0x70, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x70, 0x71, 0x3, 0x2, 0x2, 0x2, 0x71, 
       0x73, 0x3, 0x2, 0x2, 0x2, 0x72, 0x70, 0x3, 0x2, 0x2, 0x2, 0x73, 0x7d, 
       0x5, 0xe, 0x8, 0x2, 0x74, 0x75, 0x7, 0xa, 0x2, 0x2, 0x75, 0x7a, 0x5, 
       0x22, 0x12, 0x2, 0x76, 0x77, 0x7, 0x4, 0x2, 0x2, 0x77, 0x79, 0x5, 
       0x22, 0x12, 0x2, 0x78, 0x76, 0x3, 0x2, 0x2, 0x2, 0x79, 0x7c, 0x3, 
       0x2, 0x2, 0x2, 0x7a, 0x78, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x7b, 0x3, 0x2, 
       0x2, 0x2, 0x7b, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x7a, 0x3, 0x2, 0x2, 
       0x2, 0x7d, 0x74, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x7e, 0x3, 0x2, 0x2, 0x2, 
       0x7e, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x80, 0x7, 0x3, 0x2, 0x2, 0x80, 
       0x13, 0x3, 0x2, 0x2, 0x2, 0x81, 0x82, 0x7, 0x13, 0x2, 0x2, 0x82, 
       0x83, 0x7, 0x2d, 0x2, 0x2, 0x83, 0x84, 0x5, 0x10, 0x9, 0x2, 0x84, 
       0x85, 0x5, 0x24, 0x13, 0x2, 0x85, 0x15, 0x3, 0x2, 0x2, 0x2, 0x86, 
       0x87, 0x7, 0xb, 0x2, 0x2, 0x87, 0x88, 0x7, 0x2c, 0x2, 0x2, 0x88, 
       0x96, 0x7, 0xa, 0x2, 0x2, 0x89, 0x97, 0x5, 0xe, 0x8, 0x2, 0x8a, 0x8b, 
       0x7, 0xc, 0x2, 0x2, 0x8b, 0x8c, 0x7, 0x2d, 0x2, 0x2, 0x8c, 0x90, 
       0x5, 0xe, 0x8, 0x2, 0x8d, 0x8e, 0x7, 0x4, 0x2, 0x2, 0x8e, 0x8f, 0x7, 
       0x2d, 0x2, 0x2, 0x8f, 0x91, 0x5, 0xe, 0x8, 0x2, 0x90, 0x8d, 0x3, 
       0x2, 0x2, 0x2, 0x91, 0x92, 0x3, 0x2, 0x2, 0x2, 0x92, 0x90, 0x3, 0x2, 
       0x2, 0x2, 0x92, 0x93, 0x3, 0x2, 0x2, 0x2, 0x93, 0x94, 0x3, 0x2, 0x2, 
       0x2, 0x94, 0x95, 0x7, 0xd, 0x2, 0x2, 0x95, 0x97, 0x3, 0x2, 0x2, 0x2, 
       0x96, 0x89, 0x3, 0x2, 0x2, 0x2, 0x96, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x97, 
       0x98, 0x3, 0x2, 0x2, 0x2, 0x98, 0x99, 0x7, 0x3, 0x2, 0x2, 0x99, 0x17, 
       0x3, 0x2, 0x2, 0x2, 0x9a, 0x9b, 0x7, 0xb, 0x2, 0x2, 0x9b, 0x9c, 0x7, 
       0x2c, 0x2, 0x2, 0x9c, 0x9d, 0x7, 0xa, 0x2, 0x2, 0x9d, 0x9e, 0x5, 
       0x10, 0x9, 0x2, 0x9e, 0x9f, 0x7, 0x3, 0x2, 0x2, 0x9f, 0x19, 0x3, 
       0x2, 0x2, 0x2, 0xa0, 0xa3, 0x5, 0x16, 0xc, 0x2, 0xa1, 0xa3, 0x5, 
       0x18, 0xd, 0x2, 0xa2, 0xa0, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa1, 0x3, 
       0x2, 0x2, 0x2, 0xa3, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xa8, 0x5, 0x12, 
       0xa, 0x2, 0xa5, 0xa8, 0x5, 0x14, 0xb, 0x2, 0xa6, 0xa8, 0x5, 0x1a, 
       0xe, 0x2, 0xa7, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xa5, 0x3, 0x2, 0x2, 
       0x2, 0xa7, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xa8, 0x1d, 0x3, 0x2, 0x2, 0x2, 
       0xa9, 0xaa, 0x7, 0x2d, 0x2, 0x2, 0xaa, 0xab, 0x7, 0xe, 0x2, 0x2, 
       0xab, 0xac, 0x7, 0x2d, 0x2, 0x2, 0xac, 0x1f, 0x3, 0x2, 0x2, 0x2, 
       0xad, 0xb2, 0x7, 0x2d, 0x2, 0x2, 0xae, 0xaf, 0x7, 0x4, 0x2, 0x2, 
       0xaf, 0xb1, 0x7, 0x2d, 0x2, 0x2, 0xb0, 0xae, 0x3, 0x2, 0x2, 0x2, 
       0xb1, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb2, 0xb0, 0x3, 0x2, 0x2, 0x2, 0xb2, 
       0xb3, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xb2, 
       0x3, 0x2, 0x2, 0x2, 0xb5, 0xba, 0x5, 0x1e, 0x10, 0x2, 0xb6, 0xb7, 
       0x7, 0x4, 0x2, 0x2, 0xb7, 0xb9, 0x5, 0x1e, 0x10, 0x2, 0xb8, 0xb6, 
       0x3, 0x2, 0x2, 0x2, 0xb9, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xba, 0xb8, 0x3, 
       0x2, 0x2, 0x2, 0xba, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xbd, 0x3, 0x2, 
       0x2, 0x2, 0xbc, 0xba, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xbe, 0x7, 0xa, 0x2, 
       0x2, 0xbe, 0xc3, 0x5, 0x22, 0x12, 0x2, 0xbf, 0xc0, 0x7, 0x4, 0x2, 
       0x2, 0xc0, 0xc2, 0x5, 0x22, 0x12, 0x2, 0xc1, 0xbf, 0x3, 0x2, 0x2, 
       0x2, 0xc2, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xc1, 0x3, 0x2, 0x2, 0x2, 
       0xc3, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xc5, 
       0xc3, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc7, 0x7, 0x3, 0x2, 0x2, 0xc7, 0xc9, 
       0x3, 0x2, 0x2, 0x2, 0xc8, 0xad, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xb5, 0x3, 
       0x2, 0x2, 0x2, 0xc9, 0x21, 0x3, 0x2, 0x2, 0x2, 0xca, 0xcb, 0x8, 0x12, 
       0x1, 0x2, 0xcb, 0xf1, 0x5, 0x1e, 0x10, 0x2, 0xcc, 0xcd, 0x7, 0x21, 
       0x2, 0x2, 0xcd, 0xf1, 0x5, 0x22, 0x12, 0xc, 0xce, 0xcf, 0x7, 0x28, 
       0x2, 0x2, 0xcf, 0xf1, 0x5, 0x22, 0x12, 0xb, 0xd0, 0xf1, 0x7, 0x2d, 
       0x2, 0x2, 0xd1, 0xf1, 0x7, 0x2e, 0x2, 0x2, 0xd2, 0xf1, 0x7, 0x2f, 
       0x2, 0x2, 0xd3, 0xd4, 0x5, 0xe, 0x8, 0x2, 0xd4, 0xd5, 0x7, 0xc, 0x2, 
       0x2, 0xd5, 0xda, 0x5, 0x22, 0x12, 0x2, 0xd6, 0xd7, 0x7, 0x4, 0x2, 
       0x2, 0xd7, 0xd9, 0x5, 0x22, 0x12, 0x2, 0xd8, 0xd6, 0x3, 0x2, 0x2, 
       0x2, 0xd9, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xda, 0xd8, 0x3, 0x2, 0x2, 0x2, 
       0xda, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xdc, 
       0xda, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xde, 0x7, 0xd, 0x2, 0x2, 0xde, 0xf1, 
       0x3, 0x2, 0x2, 0x2, 0xdf, 0xe0, 0x7, 0x2d, 0x2, 0x2, 0xe0, 0xe2, 
       0x7, 0x7, 0x2, 0x2, 0xe1, 0xe3, 0x5, 0x22, 0x12, 0x2, 0xe2, 0xe1, 
       0x3, 0x2, 0x2, 0x2, 0xe2, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xe8, 0x3, 
       0x2, 0x2, 0x2, 0xe4, 0xe5, 0x7, 0x4, 0x2, 0x2, 0xe5, 0xe7, 0x5, 0x22, 
       0x12, 0x2, 0xe6, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xea, 0x3, 0x2, 
       0x2, 0x2, 0xe8, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xe9, 0x3, 0x2, 0x2, 
       0x2, 0xe9, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xea, 0xe8, 0x3, 0x2, 0x2, 0x2, 
       0xeb, 0xf1, 0x7, 0x8, 0x2, 0x2, 0xec, 0xed, 0x7, 0x7, 0x2, 0x2, 0xed, 
       0xee, 0x5, 0x22, 0x12, 0x2, 0xee, 0xef, 0x7, 0x8, 0x2, 0x2, 0xef, 
       0xf1, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xca, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xcc, 
       0x3, 0x2, 0x2, 0x2, 0xf0, 0xce, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xd0, 0x3, 
       0x2, 0x2, 0x2, 0xf0, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xd2, 0x3, 0x2, 
       0x2, 0x2, 0xf0, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xdf, 0x3, 0x2, 0x2, 
       0x2, 0xf0, 0xec, 0x3, 0x2, 0x2, 0x2, 0xf1, 0x100, 0x3, 0x2, 0x2, 
       0x2, 0xf2, 0xf3, 0xc, 0xe, 0x2, 0x2, 0xf3, 0xf4, 0x9, 0x2, 0x2, 0x2, 
       0xf4, 0xff, 0x5, 0x22, 0x12, 0xf, 0xf5, 0xf6, 0xc, 0xd, 0x2, 0x2, 
       0xf6, 0xf7, 0x9, 0x3, 0x2, 0x2, 0xf7, 0xff, 0x5, 0x22, 0x12, 0xe, 
       0xf8, 0xf9, 0xc, 0xa, 0x2, 0x2, 0xf9, 0xfa, 0x9, 0x4, 0x2, 0x2, 0xfa, 
       0xff, 0x5, 0x22, 0x12, 0xb, 0xfb, 0xfc, 0xc, 0x9, 0x2, 0x2, 0xfc, 
       0xfd, 0x9, 0x5, 0x2, 0x2, 0xfd, 0xff, 0x5, 0x22, 0x12, 0xa, 0xfe, 
       0xf2, 0x3, 0x2, 0x2, 0x2, 0xfe, 0xf5, 0x3, 0x2, 0x2, 0x2, 0xfe, 0xf8, 
       0x3, 0x2, 0x2, 0x2, 0xfe, 0xfb, 0x3, 0x2, 0x2, 0x2, 0xff, 0x102, 
       0x3, 0x2, 0x2, 0x2, 0x100, 0xfe, 0x3, 0x2, 0x2, 0x2, 0x100, 0x101, 
       0x3, 0x2, 0x2, 0x2, 0x101, 0x23, 0x3, 0x2, 0x2, 0x2, 0x102, 0x100, 
       0x3, 0x2, 0x2, 0x2, 0x103, 0x108, 0x7, 0xc, 0x2, 0x2, 0x104, 0x107, 
       0x5, 0x4, 0x3, 0x2, 0x105, 0x107, 0x5, 0x24, 0x13, 0x2, 0x106, 0x104, 
       0x3, 0x2, 0x2, 0x2, 0x106, 0x105, 0x3, 0x2, 0x2, 0x2, 0x107, 0x10a, 
       0x3, 0x2, 0x2, 0x2, 0x108, 0x106, 0x3, 0x2, 0x2, 0x2, 0x108, 0x109, 
       0x3, 0x2, 0x2, 0x2, 0x109, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x108, 
       0x3, 0x2, 0x2, 0x2, 0x10b, 0x10c, 0x7, 0xd, 0x2, 0x2, 0x10c, 0x25, 
       0x3, 0x2, 0x2, 0x2, 0x10d, 0x10e, 0x9, 0x6, 0x2, 0x2, 0x10e, 0x27, 
       0x3, 0x2, 0x2, 0x2, 0x10f, 0x110, 0x7, 0x1b, 0x2, 0x2, 0x110, 0x111, 
       0x5, 0x22, 0x12, 0x2, 0x111, 0x29, 0x3, 0x2, 0x2, 0x2, 0x112, 0x113, 
       0x7, 0x18, 0x2, 0x2, 0x113, 0x114, 0x5, 0x22, 0x12, 0x2, 0x114, 0x115, 
       0x7, 0x19, 0x2, 0x2, 0x115, 0x116, 0x5, 0x22, 0x12, 0x2, 0x116, 0x2b, 
       0x3, 0x2, 0x2, 0x2, 0x117, 0x118, 0x7, 0x17, 0x2, 0x2, 0x118, 0x119, 
       0x5, 0x26, 0x14, 0x2, 0x119, 0x11a, 0x7, 0x4, 0x2, 0x2, 0x11a, 0x124, 
       0x5, 0x26, 0x14, 0x2, 0x11b, 0x11d, 0x7, 0x1a, 0x2, 0x2, 0x11c, 0x11e, 
       0x7, 0x1c, 0x2, 0x2, 0x11d, 0x11c, 0x3, 0x2, 0x2, 0x2, 0x11d, 0x11e, 
       0x3, 0x2, 0x2, 0x2, 0x11e, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x125, 
       0x5, 0x22, 0x12, 0x2, 0x120, 0x122, 0x7, 0x1c, 0x2, 0x2, 0x121, 0x120, 
       0x3, 0x2, 0x2, 0x2, 0x121, 0x122, 0x3, 0x2, 0x2, 0x2, 0x122, 0x123, 
       0x3, 0x2, 0x2, 0x2, 0x123, 0x125, 0x5, 0x2a, 0x16, 0x2, 0x124, 0x11b, 
       0x3, 0x2, 0x2, 0x2, 0x124, 0x121, 0x3, 0x2, 0x2, 0x2, 0x125, 0x127, 
       0x3, 0x2, 0x2, 0x2, 0x126, 0x128, 0x5, 0x28, 0x15, 0x2, 0x127, 0x126, 
       0x3, 0x2, 0x2, 0x2, 0x127, 0x128, 0x3, 0x2, 0x2, 0x2, 0x128, 0x129, 
       0x3, 0x2, 0x2, 0x2, 0x129, 0x12a, 0x5, 0x24, 0x13, 0x2, 0x12a, 0x2d, 
       0x3, 0x2, 0x2, 0x2, 0x12b, 0x12c, 0x7, 0x14, 0x2, 0x2, 0x12c, 0x12d, 
       0x5, 0x22, 0x12, 0x2, 0x12d, 0x12e, 0x7, 0x15, 0x2, 0x2, 0x12e, 0x134, 
       0x5, 0x24, 0x13, 0x2, 0x12f, 0x132, 0x7, 0x16, 0x2, 0x2, 0x130, 0x133, 
       0x5, 0x24, 0x13, 0x2, 0x131, 0x133, 0x5, 0x2e, 0x18, 0x2, 0x132, 
       0x130, 0x3, 0x2, 0x2, 0x2, 0x132, 0x131, 0x3, 0x2, 0x2, 0x2, 0x133, 
       0x135, 0x3, 0x2, 0x2, 0x2, 0x134, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x134, 
       0x135, 0x3, 0x2, 0x2, 0x2, 0x135, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x26, 
       0x33, 0x35, 0x38, 0x3f, 0x46, 0x49, 0x4e, 0x51, 0x57, 0x5e, 0x69, 
       0x70, 0x7a, 0x7d, 0x92, 0x96, 0xa2, 0xa7, 0xb2, 0xba, 0xc3, 0xc8, 
       0xda, 0xe2, 0xe8, 0xf0, 0xfe, 0x100, 0x106, 0x108, 0x11d, 0x121, 
       0x124, 0x127, 0x132, 0x134, 
  };

  _serializedATN.insert(_serializedATN.end(), serializedATNSegment0,
    serializedATNSegment0 + sizeof(serializedATNSegment0) / sizeof(serializedATNSegment0[0]));


  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

testLanguageParser::Initializer testLanguageParser::_init;
