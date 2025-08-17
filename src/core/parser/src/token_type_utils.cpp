#include "parser/token_type_utils.hpp"

TokenTypeBP::TokenTypeBP(const FloatT lhs_bp, const FloatT rhs_bp) : lhs_bp_(lhs_bp), rhs_bp_(rhs_bp)
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
TokenType getCharTokenType(const char symbol)
{
    switch (symbol)
    {
    case '+':
        return TokenType::Addition;
    case '*':
        return TokenType::Multiplication;
    case '-':
        return TokenType::Subtraction;
    case '/':
        return TokenType::Division;
    case '(':
        return TokenType::LeftParen;
    case ')':
        return TokenType::RightParen;
    default:
        return TokenType::Error;
    }
}

bool isOperator(TokenType type) {
    
    switch (type)
    {
    case TokenType::Addition:
    case TokenType::Multiplication:
    case TokenType::Subtraction:
    case TokenType::Division:
        return true;
    }

    return false;
}