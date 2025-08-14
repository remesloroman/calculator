#pragma once

#include "math_expr/expression.hpp"

class Literal : public Expression {
public:
    FloatT eval() const override;

    std::ostream & print(std::ostream & os) const override;

    friend std::ostream & operator<<(std::ostream & os, const Literal &expr);

    Literal(FloatT rhs);
private:
    FloatT value_;
};