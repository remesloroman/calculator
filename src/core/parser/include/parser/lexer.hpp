#pragma once

#include <sstream>

#include "parser/token.hpp"

class Lexer
{
public:
    explicit Lexer(std::string input_str);

    void setInputStr(std::string input_str);

    const Token& peek() const;

    const Token& get();

    bool end() const;

    bool error() const;

private:
    Token getTokenFromStream();

    std::istringstream input_stream_;
    Token curr_;
};