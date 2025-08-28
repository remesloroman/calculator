#include "parser/parser.hpp"

#include "math_expr/expression.hpp"
#include "math_expr/literal.hpp"
#include "math_expr/addition.hpp"
#include "math_expr/multiplication.hpp"
#include "math_expr/subtraction.hpp"
#include "math_expr/division.hpp"
#include "math_expr/unary_subtraction.hpp"
#include "math_expr/unary_addition.hpp"


ExprPtr Parser::makeBinaryExpression(Tokens::Type operation, ExprPtr lhs, ExprPtr rhs)
{
    if (!lhs || !rhs)
    {
        return nullptr;
    }

    switch (operation)
    {
    case Tokens::Type::Addition:
        return std::make_unique<Addition>(std::move(lhs), std::move(rhs));
    case Tokens::Type::Multiplication:
        return std::make_unique<Multiplication>(std::move(lhs), std::move(rhs));
    case Tokens::Type::Subtraction:
        return std::make_unique<Subtraction>(std::move(lhs), std::move(rhs));
    case Tokens::Type::Division:
        return std::make_unique<Division>(std::move(lhs), std::move(rhs));
    default:
        throw std::invalid_argument("Parser::makeBinaryExpression: operation is not a valid binary operation");
    }
}

ExprPtr Parser::makeUnaryExpression(Tokens::Type operation, ExprPtr rhs)
{
    if (!rhs)
    {
        return nullptr;
    }
    switch (operation)
    {
    case Tokens::Type::Subtraction:
        return std::make_unique<UnarySubtraction>(std::move(rhs));
    case Tokens::Type::Addition:
        return std::make_unique<UnaryAddition>(std::move(rhs));
    default:
        throw std::invalid_argument("Parser::makeUnaryExpression: operation is not a valid unary operation");
    }
}

Parser::Parser(std::string input_str) : lexer_(std::move(input_str))
{
}

void Parser::setInputStr(std::string input_str)
{
    lexer_.setInputStr(std::move(input_str));
}

ExprPtr Parser::parse()
{
    ExprPtr expr = parseImpl(DEFAULT_BP);
    return lexer_.next().end() ? std::move(expr) : nullptr;
}


ExprPtr Parser::parseImpl(const FloatT min_bind_power)
{
    ExprPtr lhs = parsePrefix();
    return parseInfix(min_bind_power, std::move(lhs));
}

ExprPtr Parser::parsePrefix()
{
    switch (const Tokens::Token token = lexer_.next().curr(); token.type())
    {
    case Tokens::Type::LeftParen:
        {
            if (ExprPtr lhs = parseImpl(DEFAULT_BP); lexer_.peek().type() == Tokens::Type::RightParen)
            {
                lexer_.next();
                return lhs;
            }
            return nullptr;
        }
    case Tokens::Type::Subtraction:
        {
            ExprPtr rhs = parseImpl(Tokens::unaryTypeBindingPower(token.type()));
            return makeUnaryExpression(token.type(), std::move(rhs));
        }
    case Tokens::Type::Addition:
        {
            ExprPtr rhs = parseImpl(Tokens::unaryTypeBindingPower(token.type()));
            return makeUnaryExpression(token.type(), std::move(rhs));
        }
    case Tokens::Type::Literal:
        return ExprPtr(new Literal(token.value()));
    default:
        return nullptr;
    }
}

ExprPtr Parser::parseInfix(const FloatT min_bind_power, ExprPtr lhs)
{
    while (true)
    {
        Tokens::Token token = lexer_.peek();
        if (token.type() == Tokens::Type::EndOfFile ||
            token.type() == Tokens::Type::RightParen)
        {
            break;
        }
        if (!Tokens::typeIsOperator(token.type()))
        {
            return nullptr;
        }

        auto [lhs_bind_power, rhs_bind_power] = Tokens::binaryTypeBindingPower(token.type());
        if (lhs_bind_power < min_bind_power)
        {
            break;
        }

        lexer_.next();

        ExprPtr rhs = parseImpl(rhs_bind_power);
        lhs = makeBinaryExpression(token.type(), std::move(lhs), std::move(rhs));
    }

    return lhs;
}
