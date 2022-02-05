
// Generated from testLanguage.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"




class  testLanguageLexer : public antlr4::Lexer {
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

  explicit testLanguageLexer(antlr4::CharStream *input);
  ~testLanguageLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

