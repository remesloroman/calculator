#include <stdexcept>

#include "parser/token.hpp"

Token::Token(TokenType type) : type_(type), val_(DEFAULT_VAL)
{
}

Token::Token(FloatT val) : type_(TokenType::Literal), val_(val)
{
}

TokenType Token::type() const
{
    return type_;
}

bool Token::hasValue() const
{
    return type_ == TokenType::Literal;
}

FloatT Token::val() const
{
    if (!hasValue())
    {
        throw std::runtime_error("Token::val: Following type of token cannot have a value");
    }

    return val_;
}