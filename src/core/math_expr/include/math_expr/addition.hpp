#pragma once

#include "math_expr/binary_expression.hpp"

class Addition : public BinaryExpression
{
public:
    Addition(ExprPtr lhs, ExprPtr rhs);

    FloatT eval() const override;

    std::ostream &print(std::ostream &os) const override;

    friend std::ostream &operator<<(std::ostream &os, const Addition &add_expr); 

};