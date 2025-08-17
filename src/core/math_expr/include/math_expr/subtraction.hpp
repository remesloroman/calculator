#pragma once

#include "math_expr/expression.hpp"

class Subtraction : public Expression
{
public:
    Subtraction(ExprPtr lhs, ExprPtr rhs);

    FloatT eval() const override;

    std::ostream &print(std::ostream &os) const override;

    friend std::ostream &operator<<(std::ostream &os, const Subtraction &sub_expr); 
private: 
    ExprPtr lhs_;
    ExprPtr rhs_;
};