#include "./lex.hpp"
#include "Token.hpp"
#include <iostream>
#include <string>

using namespace std;

int main() {
  Lexer lex("sample.cpp");
  string s;
  Token *t;
  TokenVector tv;
  while (true) {
    t = lex.getToken();
    tv.push_back(t);
    if (t->getString() == "EOF") {
      break;
    }
  }
  for (auto it : tv.tokenVector)
    cout << *it << endl;
  return 0;
}
