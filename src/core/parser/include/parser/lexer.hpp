#pragma once

#include <sstream>

#include "parser/token.hpp"

class Lexer
{
public:
    Lexer(std::string input_str);

    void str(std::string input_str);

    Token curr() const;

    Lexer &next();

    bool end() const;

    bool error() const;

private:
    Token getTokenFromStream();

    std::istringstream input_stream_;
    Token curr_;
};