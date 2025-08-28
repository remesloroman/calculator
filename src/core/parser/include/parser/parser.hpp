#pragma once

#include "parser/lexer.hpp"
#include "math_expr/expression.hpp"
#include "alias/alias.hpp"

class Parser
{
    static constexpr FloatT DEFAULT_BP = 0.0;

    static ExprPtr makeBinaryExpression(Tokens::Type operation, ExprPtr lhs, ExprPtr rhs);

    static ExprPtr makeUnaryExpression(Tokens::Type operation, ExprPtr rhs);

public:
    explicit Parser(std::string input_str);

    void setInputStr(std::string input_str);

    ExprPtr parse();

private:
    ExprPtr parseImpl(FloatT min_bind_power);

    ExprPtr parsePrefix();

    ExprPtr parseInfix(FloatT min_bind_power, ExprPtr lhs);

    Lexer lexer_;
};
