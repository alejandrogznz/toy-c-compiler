#include "./lex.hpp"
#include "Token.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  Lexer lex("sample.cpp");
  string s;
  vector<Token> tv;
  Token t;
  while (true) {
    t = lex.getToken();
    cout << t << endl;
    if (t.getString() == "EOF") {
      cout << "End of File" << endl;
      break;
    }
  }
}
