#include "math_expr/expression.hpp"

std::ostream &operator<<(std::ostream &os, const Expression &expr){
    return expr.print(os);
}