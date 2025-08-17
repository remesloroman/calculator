#include "math_expr/subtraction.hpp"

Subtraction::Subtraction(ExprPtr lhs, ExprPtr rhs) : lhs_(std::move(lhs)), rhs_(std::move(rhs)){

}

FloatT Subtraction::eval() const{
    return lhs_->eval() - rhs_->eval();
}

std::ostream &Subtraction::print(std::ostream &os) const{
    return os << *lhs_ << " - " << *rhs_;
}

std::ostream &operator<<(std::ostream &os, const Subtraction &sub_expr){
    return sub_expr.print(os);
}