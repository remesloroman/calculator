#pragma once

#include "math_expr/expression.hpp"

class BinaryExpression : public Expression {
public:
    BinaryExpression(ExprPtr lhs, ExprPtr rhs);
protected:
    ExprPtr lhs_;
    ExprPtr rhs_;
};