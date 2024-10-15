#include "Token.hpp"

Token::Token() {}

Token::Token(Token &token)
    : tokenString(token.tokenString), tokenType(token.tokenType) {}
Token::Token(std::string s) : tokenString(s) {
  std::cout << "Creating Token from: " + this->tokenString << std::endl;
  if (this->tokenString == "(") {
    this->tokenType = TokenType::LEFT_PAREN;
  } else if (this->tokenString == ")") {
    this->tokenType = TokenType::RIGHT_PAREN;
  } else if (this->tokenString == "EOF") {
    this->tokenType = TokenType::eof;
    std::cout << "Found EOF" << std::endl;
  }
}

const std::string Token::getString() { return tokenString; }

TokenType Token::getType() { return tokenType; }

std::ostream &operator<<(std::ostream &os, const Token &t) {
  os << t.tokenString << " ";
  return os;
}
