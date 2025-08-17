#pragma once

#include <sstream>
#include <queue>
#include "parser/token.hpp"

class Lexer {
public:
    Lexer() = default;

    Lexer(std::string is);

    Token next();

    Token peek();

    Token current();

    void initialize(std::string input);
private:
    std::istringstream source_;
    std::queue<Token> tokens_;
    Token current_ = Token(TokenType::EndOfFile);

    Token itterate();

    void skipSpaces();

    bool checkEOF();
};