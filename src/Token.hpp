#pragma once

#include <iostream>
#include <string>
#include <vector>

enum class TokenType {
  ERROR,
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
  ID,
  // Literals
  //
  // Keywords
  INT,
  RETURN,
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

  std::string getString() const;

  std::string getTypeString() const;

  TokenType getType();

  friend std::ostream &operator<<(std::ostream &os, const Token &t);
};

class TokenVector {

public:
  std::vector<Token *> tokenVector;

  TokenVector() = default;

  Token *push_back(Token *t);

  // TODO Implement TokenVector::pop_back
  bool pop_back();

  std::vector<Token *>::iterator begin();

  std::vector<Token *>::iterator end();

  ~TokenVector();

private:
};
