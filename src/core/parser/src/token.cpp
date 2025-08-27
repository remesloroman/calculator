#include <stdexcept>

#include "parser/token.hpp"

namespace Tokens
{
    Token::Token(const Type token_type) : type_(token_type), val_(DEFAULT_VAL)
    {
    }

    Token::Token(const FloatT value) : type_(Type::Literal), val_(value)
    {
    }

    Type Token::type() const
    {
        return type_;
    }

    bool Token::hasValue() const
    {
        return type() == Type::Literal;
    }

    FloatT Token::value() const
    {
        if (!hasValue())
        {
            throw std::runtime_error("Token::val: following type of token cannot have a value");
        }
        return val_;
    }
}
