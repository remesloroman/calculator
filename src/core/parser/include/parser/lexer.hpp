#include <istream>
#include "parser/token.hpp"

class Lexer {
public:
    Lexer() = default;

    Token next();

    char skipSpaces();
private:
    std::istream source;
};