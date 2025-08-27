#include "math_expr/binary_expression.hpp"

BinaryExpression::BinaryExpression(ExprPtr lhs, ExprPtr rhs): 
    lhs_(std::move(lhs)), rhs_(std::move(rhs)) {}