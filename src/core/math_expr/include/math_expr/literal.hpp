#pragma once
#include "expression.hpp"
#include "../alias.hpp"
#include <iostream>

class Literal : public Expression {
public:
    FloatT eval() const override;

    std::ostream & print(std::ostream & os) const override;

    friend std::ostream & operator<<(std::ostream & os, const Literal &expr);

    Literal(FloatT rhs);
private:
    FloatT value_;
};