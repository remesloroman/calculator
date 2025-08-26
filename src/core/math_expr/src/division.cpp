#include "math_expr/division.hpp"

Division::Division(ExprPtr lhs, ExprPtr rhs) 
: BinaryExpression(std::move(lhs), std::move(rhs)){

}

FloatT Division::eval() const{
    return lhs_->eval() / rhs_->eval();
}

std::ostream &Division::print(std::ostream &os) const{
    return os << *lhs_ << " / " << *rhs_;
}

std::ostream &operator<<(std::ostream &os, const Division &div_expr){
    return div_expr.print(os);
}