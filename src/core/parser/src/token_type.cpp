#include <stdexcept>

#include "parser/token_type.hpp"

namespace Tokens
{
    bool typeIsOperator(const Type token_type)
    {
        switch (token_type)
        {
        case Type::Addition:
            return true;
        case Type::Multiplication:
            return true;
        case Type::Subtraction:
            return true;
        case Type::Division:
            return true;
        default:
            return false;
        }
    }

    Type typeFromChar(const char character)
    {
        switch (character)
        {
        case '+':
            return Type::Addition;
        case '*':
            return Type::Multiplication;
        case '-':
            return Type::Subtraction;
        case '/':
            return Type::Division;
        case '(':
            return Type::LeftParen;
        case ')':
            return Type::RightParen;
        default:
            return Type::Error;
        }
    }

    std::pair<FloatT, FloatT> typeBindingPower(const Type token_type)
    {
        switch (token_type)
        {
        case Type::Addition:
            return {1.0, 1.1};
        case Type::Multiplication:
            return {2.0, 2.1};
        case Type::Subtraction:
            return {1.0, 1.1};
        case Type::Division:
            return {2.0, 2.1};
        default:
            throw std::invalid_argument("typeBindingPower: token_type cannot have a binding power");
        }
    }
}
