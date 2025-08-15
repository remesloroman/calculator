#include "parser/token_type.hpp"

TokenTypeBP::TokenTypeBP(const FloatT lhs_bp, const FloatT rhs_bp) : lhs_bp_(lhs_bp), rhs_bp_(rhs_bp)
{
}

TokenTypeBP::TokenTypeBP(const std::pair<FloatT, FloatT> bp) : lhs_bp_(bp.first), rhs_bp_(bp.second)
{
}

TokenTypeBP getTokenTypeBP(TokenType type)
{
    switch (type)
    {
    case TokenType::Addition:
        return {1.1, 1.0};

    case TokenType::Multiplication:
        return {2.1, 2.0};

    case TokenType::Subtraction:
        return {1.1, 1.0};

    case TokenType::Division:
        return {2.1, 2.0};

    default:
        return {0, 0};
    }
}

char getTokenTypeChar(TokenType type)
{
    switch (type)
    {
    case TokenType::Addition:
        return '+';

    case TokenType::Multiplication:
        return '*';

    case TokenType::Subtraction:
        return '-';

    case TokenType::Division:
        return '/';

    case TokenType::LeftParen:
        return '(';

    case TokenType::RightParen:
        return ')';

    default:
        return '\0';
    }
}