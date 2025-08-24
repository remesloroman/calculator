#pragma once

#include "parser/token_type.hpp"
#include "alias/alias.hpp"

struct TokenTypeBP
{
    TokenTypeBP(FloatT lhs_bp, FloatT rhs_bp);

    FloatT lhs_bp_;
    FloatT rhs_bp_;
};

TokenTypeBP getTokenTypeBP(TokenType type);

TokenType getCharTokenType(const char symbol);

bool isOperator(TokenType type);