#pragma once

#include "Token.hpp"

#include <ctype.h>
#include <fstream>
#include <iostream>
#include <string>

class Lexer {

  std::ifstream mifs;

  Lexer() = delete;

public:
  Lexer(std::string filename);

  Token *getToken();

  ~Lexer();

private:
  char getChar();
};
