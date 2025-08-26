#include "math_expr/unary_expression.hpp"

UnaryExpression::UnaryExpression(ExprPtr rhs): rhs_(std::move(rhs)) 
    {}