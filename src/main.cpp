#include <iostream>

#include "./lex.hpp"

using namespace std;

int main()
{
    TokenType tt = TokenType::If;
    if (tt == TokenType::If) 
        cout << "Is If Token" << endl;
}
