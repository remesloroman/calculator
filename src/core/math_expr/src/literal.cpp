#include "math_expr/literal.hpp"

Literal::Literal(FloatT rhs) : value_(rhs) {}

FloatT Literal::eval() const {
    return value_;
}

std::ostream & Literal::print(std::ostream & os) const {
    return os << value_;
}

std::ostream & operator<<(std::ostream & os, const Literal &expr) {
    expr.print(os);
    
    return os;
}