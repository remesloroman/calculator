#pragma once

#include "math_expr/expression.hpp"

class UnaryExpression : public Expression {
public:
    UnaryExpression(ExprPtr rhs);
protected:
    ExprPtr rhs_;
};