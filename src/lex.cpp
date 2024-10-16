#include "lex.hpp"

Lexer::Lexer(std::string filename) : mifs(filename, std::ifstream::in) {}

Lexer::~Lexer() {
  if (mifs.is_open()) {
    std::cout << "Closing \"mifs\" stream" << std::endl;
    mifs.close();
  }
}

Token *Lexer::getToken() {
  std::string s = "";
  char c;

  // Skip leading whitespace
  while (isspace(mifs.peek())) {
    mifs.get(c);
  }

  while (mifs.good()) {
    c = mifs.peek();

    // If whitespace is found, end the token read
    if (isspace(c)) {
      mifs.get(c);
      break;
    }

    // If EOF found, close file
    if (c == EOF) {
      return new Token{"EOF"};
    }

    // If separator is found, end statement
    if (c == ';') {
      // If there are previous chars read, return the current built string
      // Otherwise, return ';' token
      if (s.size() > 0)
        break;
      mifs.get(c);
      return new Token{";"};
    }

    if (c == '(') {
      // If there are previous chars read, return the current built string
      // Otherwise, return ';' token
      if (s.size() > 0)
        break;
      mifs.get(c);
      return new Token{"("};
    }

    if (c == ')') {
      // If there are previous chars read, return the current built string
      // Otherwise, return ';' token
      if (s.size() > 0)
        break;
      mifs.get(c);
      return new Token{")"};
    }
    if (c == '{') {
      // If there are previous chars read, return the current built string
      // Otherwise, return ';' token
      if (s.size() > 0)
        break;
      mifs.get(c);
      return new Token{"{"};
    }
    if (c == '}') {
      // If there are previous chars read, return the current built string
      // Otherwise, return '}' token
      if (s.size() > 0)
        break;
      mifs.get(c);
      return new Token{"}"};
    }

    if (c == '>') {
      // If there are previous chars read, return the current built string
      // Otherwise, return '>' token
      if (s.size() > 0)
        break;
      mifs.get(c);
      return new Token{">"};
    }
    if (c == '<') {
      // If there are previous chars read, return the current built string
      // Otherwise, return '<' token
      if (s.size() > 0)
        break;
      mifs.get(c);
      return new Token{"<"};
    }

    if (c == '#') {
      // If there are previous chars read, return the current built string
      // Otherwise, return ';' token
      if (s.size() > 0)
        break;
      mifs.get(c);
      return new Token{"#"};
    }
    mifs.get(c);
    s += c;
  }

  if (mifs.eof()) {
    return new Token{"EOF"};
  }

  return new Token{s};
}

char Lexer::getChar() {
  char c;
  if (mifs.get(c))
    return c;
  return EOF;
}
