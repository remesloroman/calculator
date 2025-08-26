#include "math_expr/addition.hpp"

Addition::Addition(ExprPtr lhs, ExprPtr rhs) : BinaryExpression(std::move(lhs), std::move(rhs)){

}

FloatT Addition::eval() const{
    return lhs_->eval() + rhs_->eval();
}

std::ostream &Addition::print(std::ostream &os) const{
    return os << *lhs_ << " + " << *rhs_;
}

std::ostream &operator<<(std::ostream &os, const Addition &add_expr){
    return add_expr.print(os);
}