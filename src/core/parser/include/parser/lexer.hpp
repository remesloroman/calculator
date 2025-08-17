#include <sstream>
#include <queue>
#include "parser/token.hpp"

class Lexer {
public:
    Lexer(std::string is);

    Token next();

    Token peek();

    Token current();
private:
    std::istringstream source_;
    std::queue<Token> tokens_;
    Token current_;

    Token itterate();

    void skipSpaces();

    bool checkEOF();
};