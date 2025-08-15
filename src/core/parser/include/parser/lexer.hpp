#include <sstream>
#include "parser/token.hpp"

class Lexer {
public:
    Lexer(std::string is);

    Token next();

    void skipSpaces();

    bool checkEOF();
private:
    std::istringstream source_;
};