#pragma once

#include <iostream>
#include <string>

enum class TokenType {
  // Single Character Tokens
  NNULL,
  LEFT_PAREN,
  RIGHT_PAREN,
  LEFT_BRACE,
  RIGHT_BRACE,
  COMMA,
  DOT,
  MINUS,
  PLUS,
  SEMICOLON,

  // One or Two Character Tokens

  // Literals
  //
  // Keywords
  //
  // EOF
  eof
};

class Token {

  std::string tokenString;

  TokenType tokenType;

public:
  Token();

  Token(Token &s);

  Token(std::string s);

  const std::string getString();

  TokenType getType();

  friend std::ostream &operator<<(std::ostream &os, const Token &t);
};
