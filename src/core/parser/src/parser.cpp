#include "parser/parser.hpp"

void Parser::setInputString(std::string input) {
    lexer.initialize(input);
}

Parser::Parser(std::string input) {
    setInputString(input);
}

ExprPtr Parser::parse() {
    return parse_expression(lexer, 0.0);
}

ExprPtr Parser::make_expression(TokenType op, ExprPtr lhs, ExprPtr rhs) {
    switch (op)
    {
    case TokenType::Addition:
        return std::make_unique<Addition>(std::move(lhs), std::move(rhs));
        break;
    case TokenType::Subtraction:
        return std::make_unique<Subtraction>(std::move(lhs), std::move(rhs));
        break;
    case TokenType::Multiplication:
        return std::make_unique<Multiplication>(std::move(lhs), std::move(rhs));
        break;
    case TokenType::Division:
        return std::make_unique<Division>(std::move(lhs), std::move(rhs));
        break;
    }

    return nullptr;
}

ExprPtr Parser::parseInfixLoop(Lexer & lexer, ExprPtr lhs, FloatT min_bp) {
    while(true) {
        Token token = lexer.peek();

        if (token.type() == TokenType::RightParen) 
            break;
        else if(token.type() == TokenType::EndOfFile)
            break;
        else if(!isOperator(token.type()))
            throw std::runtime_error("parseInfixLoop: unexpected symbol");

        TokenTypeBP bp = getTokenTypeBP(token.type());

        if(bp.lhs_bp_ < min_bp) break;

        lexer.next();

        ExprPtr rhs = parse_expression(lexer, bp.rhs_bp_);

        lhs = make_expression(token.type(), std::move(lhs), std::move(rhs));
    }

    return lhs;
}

ExprPtr Parser::parsePrefix(Lexer & lexer) {
    Token token = lexer.next();

    switch(token.type()) {
        case TokenType::Literal:
            return std::make_unique<Literal>(token.val());
        case TokenType::LeftParen:
            return parse_expression(lexer, 0.0);
        default:
            throw std::runtime_error("Parser.parsePrefix: unexpected symbol");
    }

    return nullptr;
}

ExprPtr Parser::parse_expression(Lexer & lexer, FloatT min_bp) {
    ExprPtr lhs = parsePrefix(lexer);

    lhs = parseInfixLoop(lexer, std::move(lhs), min_bp);    

    return lhs;
}