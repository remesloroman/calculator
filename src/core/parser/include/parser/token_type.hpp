#pragma once

#include <map>
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

struct TokenTypeBP
{
    TokenTypeBP(FloatT lhs_bp, FloatT rhs_bp);

    TokenTypeBP(std::pair<FloatT, FloatT> bp);

    FloatT lhs_bp_;
    FloatT rhs_bp_;
};

TokenTypeBP getTokenTypeBP(TokenType type);

char getTokenTypeChar(TokenType type);