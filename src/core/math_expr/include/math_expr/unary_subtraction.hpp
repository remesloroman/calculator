#pragma once

#include "math_expr/unary_expression.hpp"

class UnarySubtraction : public UnaryExpression {
public:
    UnarySubtraction(ExprPtr rhs);

    std::ostream &print(std::ostream &os) const override;

    FloatT eval() const override;
};