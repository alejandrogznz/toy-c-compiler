#include "Token.hpp"

Token::Token(std::string s)
    :tokenString(s)
{
}

std::string Token::getString()
{
    return tokenString;
}
