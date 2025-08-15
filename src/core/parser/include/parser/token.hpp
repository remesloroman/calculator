#pragma once

#include "../../alias.hpp"

enum class TokenType
{
    EndOfFile,
    Error,

    Literal,
    Addition,
    Multiplication,
    Subtraction,
    Division,

    LeftParen,
    RightParen

};

class Token
{
public:
    static constexpr FloatT DEFAULT_VAL = 0;

    explicit Token(TokenType type);

    explicit Token(FloatT val);

    TokenType type() const;

    bool hasValue() const;

    FloatT val() const;

private:
    TokenType type_;
    FloatT val_;
};