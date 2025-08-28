#pragma once

#include "math_expr/unary_expression.hpp"

class UnaryAddition : public UnaryExpression {
public:
    UnaryAddition(ExprPtr rhs);

    std::ostream &print(std::ostream &os) const override;

    FloatT eval() const override;
};