#include "Token.hpp"
#include <cstdlib>

Token::Token() {}

Token::Token(Token &token)
    : tokenString(token.tokenString), tokenType(token.tokenType) {}
Token::Token(std::string s) : tokenString(s) {
  std::cout << "Creating Token from: " + this->tokenString << std::endl;
  if (this->tokenString == "(") {
    this->tokenType = TokenType::LEFT_PAREN;
  } else if (this->tokenString == ")") {
    this->tokenType = TokenType::RIGHT_PAREN;
  } else if (this->tokenString == "{") {
    this->tokenType = TokenType::LEFT_BRACE;
  } else if (this->tokenString == "}") {
    this->tokenType = TokenType::RIGHT_BRACE;
  } else if (this->tokenString == "int") {
    this->tokenType = TokenType::INT;
  } else if (this->tokenString == "return") {
    this->tokenType = TokenType::RETURN;
  } else if (this->tokenString == "EOF") {
    this->tokenType = TokenType::eof;
    std::cout << "Found EOF" << std::endl;
  } else {
    this->tokenType = TokenType::ID;
  }
}

std::string Token::getString() const { return tokenString; }

std::string Token::getTypeString() const {
  TokenType tt = TokenType::ERROR;
  tt = this->tokenType;
  switch (tt) {
  case TokenType::ID:
    return "ID";
  case TokenType::INT:
    return "int";

  case TokenType::LEFT_PAREN:
    return "LEFT_PAREN";

  case TokenType::RIGHT_PAREN:
    return "RIGHT_PAREN";
  case TokenType::LEFT_BRACE:
    return "LEFT_BRACE";
  case TokenType::RIGHT_BRACE:
    return "RIGHT_BRANCE";
  case TokenType::RETURN:
    return "RETURN";
  case TokenType::eof:
    return "EOF";
  default:
    std::cout << "Unknown Token from " + this->tokenString << std::endl;
    exit(0);
  }
  return "";
}
TokenType Token::getType() { return tokenType; }

std::ostream &operator<<(std::ostream &os, const Token &t) {

  os << "Value: \"" << t.tokenString << "\" Type: " << t.getTypeString();
  return os;
}

// Token Vector
Token *TokenVector::push_back(Token *t) {
  tokenVector.push_back(t);
  return t;
}

std::vector<Token *>::iterator TokenVector::begin() {
  return tokenVector.begin();
}

std::vector<Token *>::iterator TokenVector::end() { return tokenVector.end(); }
TokenVector::~TokenVector() {
  for (Token *t : tokenVector) {
    delete t;
  }
}
