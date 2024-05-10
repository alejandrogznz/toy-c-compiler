#pragma once

#include "Token.hpp"

#include <string>
#include <fstream>
#include <iostream>
#include <ctype.h>

class Lexer {
    
    std::ifstream mifs;

    Lexer() = delete;

    public:

    Lexer(std::string filename);

    Token getToken();

    ~Lexer();
    
    private:

    char getChar();
};
