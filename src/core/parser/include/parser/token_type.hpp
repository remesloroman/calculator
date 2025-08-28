#pragma once

#include "alias/alias.hpp"

namespace Tokens
{
    enum class Type
    {
        None,
        EndOfFile,
        Error,

        Literal,
        Addition,
        Multiplication,
        Subtraction,
        Division,

        LeftParen,
        RightParen,

    };
    bool typeIsOperator(Type token_type);

    Type typeFromChar(char character);

    std::pair<FloatT,FloatT> typeBindingPower(Type token_type);
}




