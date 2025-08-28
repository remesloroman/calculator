#pragma once

#include <sstream>

#include "parser/token.hpp"

class Lexer
{
public:
    explicit Lexer(std::string input_str);

    void setInputStr(std::string input_str);

    const Tokens::Token& peek() const;

    const Tokens::Token& curr() const;

    Lexer& next();

    bool end() const;

    bool error() const;

private:
    Tokens::Token getTokenFromStream();

    std::istringstream input_stream_;

    Tokens::Token curr_;

    Tokens::Token next_;
};