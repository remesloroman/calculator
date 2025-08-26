#pragma once

#include "math_expr/binary_expression.hpp"

class Subtraction : public BinaryExpression
{
public:
    Subtraction(ExprPtr lhs, ExprPtr rhs);

    FloatT eval() const override;

    std::ostream &print(std::ostream &os) const override;

    friend std::ostream &operator<<(std::ostream &os, const Subtraction &sub_expr); 

};