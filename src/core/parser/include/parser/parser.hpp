#pragma once

#include "parser/lexer.hpp"
#include "math_expr/expression.hpp"
#include "math_expr/literal.hpp"
#include "math_expr/addition.hpp"
#include "math_expr/subtraction.hpp"
#include "math_expr/multiplication.hpp"
#include "math_expr/division.hpp"
#include "parser/token_type_utils.hpp"

class Parser {
public:
    Parser() = default;

    Parser(std::string input);

    void setInputString(std::string input);

    ExprPtr parse();

private:
    ExprPtr makeExpression(TokenType op, ExprPtr lhs, ExprPtr rhs);
    ExprPtr parseExpression(Lexer & lexer, FloatT min_bp);
    ExprPtr parseInfixLoop(Lexer & lexer, ExprPtr lhs, FloatT min_bp);
    ExprPtr parsePrefix(Lexer & lexer);

    Lexer lexer_;
   
};