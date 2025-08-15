#include "parser/lexer.hpp"

char Lexer::skipSpaces() {
    char symbol;
    while (source.get(symbol)) {
        if (!std::isspace(static_cast<unsigned char>(symbol))) {
            return symbol;
        }
    }
    return EOF;
}

Token Lexer::next() {
    char symbol = skipSpaces();

    if(symbol == EOF) return Token(TokenType::EndOfFile); // Return EOF
    
    if(std::isdigit(symbol)) {
        source.unget();
        double value = 0.0;
        if(!(source >> value)) return Token(TokenType::Error); // Return ERR

        return Token(value); // Return LITERAL
    } 

    symbol = skipSpaces();
    
    switch (symbol) {
        case '+': return Token(TokenType::Addition);
        case '-': return Token(TokenType::Subtraction);
        case '*': return Token(TokenType::Multiplication);
        case '/': return Token(TokenType::Division);
        case '(': return Token(TokenType::LeftParen);
        case ')': return Token(TokenType::RightParen);
    }


    return Token(TokenType::Error); // Return ERR
}