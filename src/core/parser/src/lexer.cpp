#include "parser/lexer.hpp"
#include "parser/token_type_utils.hpp"

Lexer::Lexer(std::string is)
{
    initialize(is);
}

void Lexer::skipSpaces()
{
    while (std::isspace(static_cast<unsigned char>(source_.peek())))
    {
        source_.get();
    }
}

bool Lexer::checkEOF()
{
    int symbol = source_.peek();

    if (symbol == EOF)
    {
        return true;
    }

    return false;
}

Token Lexer::next() {
    current_ = tokens_.front();
    tokens_.pop();

    return current_;
}

Token Lexer::peek() {
    return tokens_.front();
}

Token Lexer::itterate()
{
    skipSpaces();

    if (checkEOF()) return Token(TokenType::EndOfFile);

    char symbol = source_.peek();

    if (std::isdigit(static_cast<unsigned char>(symbol)))
    {
        double value = 0.0;
        if (!(source_ >> value)) return Token(TokenType::Error);

        return Token(value);
    }

    source_.get();

    return Token(getCharTokenType(symbol));
}

Token Lexer::current() {
    return current_;
}

void Lexer::initialize(std::string input) {
    source_.clear();
    source_.str(input);

    // Clear queue
    while(!tokens_.empty()) tokens_.pop();

    Token current = itterate();
    tokens_.push(current);

    // Init current_
    current_ = current;

    while(current.type() != TokenType::EndOfFile) {
        current = itterate();
        tokens_.push(current);
    }
}