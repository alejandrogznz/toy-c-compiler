#include "./lex.hpp"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    Lexer lex("sample.cpp");
    string s;

    while ((s = lex.getToken().getString()) != "")
        cout << s << endl;
}
