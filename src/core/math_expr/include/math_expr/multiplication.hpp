#pragma once

#include "math_expr/binary_expression.hpp"

class Multiplication : public BinaryExpression
{
public:
    Multiplication(ExprPtr lhs, ExprPtr rhs);

    FloatT eval() const override;

    std::ostream &print(std::ostream &os) const override;

    friend std::ostream &operator<<(std::ostream &os, const Multiplication &mult_expr); 
private: 
    ExprPtr lhs_;
    ExprPtr rhs_;
};