#pragma once
#include <string>

enum class TokenType
{
    If,
    Int,
    Main,
    Op,
    Cp,
    Ob,
    Cb
};

class Token {

    std::string tokenString;

    public:
    
    Token(std::string s);

    std::string getString();

};

