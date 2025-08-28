#include "math_expr/unary_addition.hpp"

UnaryAddition::UnaryAddition(ExprPtr rhs): UnaryExpression(std::move(rhs)) 
    {}

std::ostream &UnaryAddition::print(std::ostream &os) const {
    return os << "-" << *rhs_;
}

FloatT UnaryAddition::eval() const {
    return +rhs_->eval();
}