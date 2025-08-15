#include <sstream>
#include "parser/token.hpp"

class Lexer {
public:
    Lexer() = default;
    Lexer(std::string is): source(is) {}

    Token next();

    void skipSpaces();

    bool checkEOF();
private:
    std::istringstream source;
};