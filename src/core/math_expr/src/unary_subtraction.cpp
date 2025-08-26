#include "math_expr/unary_subtraction.hpp"

UnarySubtraction::UnarySubtraction(ExprPtr rhs): UnaryExpression(std::move(rhs)) 
    {}

std::ostream &UnarySubtraction::print(std::ostream &os) const {
    return os << "-" << *rhs_;
}

FloatT UnarySubtraction::eval() const {
    return -rhs_->eval();
}