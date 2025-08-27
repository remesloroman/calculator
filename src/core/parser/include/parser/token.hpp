#pragma once

#include "alias/alias.hpp"
#include "parser/token_type.hpp"

namespace Tokens
{
    class Token
    {
    public:
        static constexpr FloatT DEFAULT_VAL = 0;

        explicit Token(Type token_type);

        explicit Token(FloatT value);

        Type type() const;

        bool hasValue() const;

        FloatT value() const;

    private:
        Type type_;
        FloatT val_;
    };
}
