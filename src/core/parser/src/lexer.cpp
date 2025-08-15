#include "parser/lexer.hpp"
#include "parser/token_type_utils.hpp"

Lexer::Lexer(std::string is) : source_(is)
{
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

Token Lexer::next()
{
    skipSpaces();

    if (checkEOF())
        return Token(TokenType::EndOfFile);

    char symbol = source_.peek();

    if (std::isdigit(static_cast<unsigned char>(symbol)))
    {
        double value = 0.0;
        if (!(source_ >> value))
            return Token(TokenType::Error);

        return Token(value);
    }

    source_.get();
    return Token(getCharTokenType(symbol));
}