#include "parser/lexer.hpp"

#include "parser/token_type.hpp"
#include "parser/token_type_utils.hpp"

Lexer::Lexer(std::string input_str) : input_stream_(std::move(input_str)), curr_(getTokenFromStream())
{
}

void Lexer::setInputStr(std::string input_str)
{
    input_stream_.clear();
    input_stream_.str(std::move(input_str));
    curr_ = getTokenFromStream();
}

const Token& Lexer::peek() const
{
    return curr_;
}

Token Lexer::getTokenFromStream()
{
    input_stream_ >> std::ws;
    if (input_stream_.eof())
    {
        return Token{TokenType::EndOfFile};
    }

    char character = input_stream_.peek();
    if (std::isdigit(static_cast<unsigned char>(character)))
    {
        FloatT value = 0.0;
        if (!(input_stream_ >> value))
            return Token{TokenType::Error};

        return Token{value};
    }

    input_stream_.get();
    return Token{getCharTokenType(character)};
}

const Token& Lexer::get()
{
    if (!end() && !error())
    {
        curr_ = getTokenFromStream();
    }

    return peek();
}

bool Lexer::end() const
{
    return curr_.type() == TokenType::EndOfFile;
}

bool Lexer::error() const
{
    return curr_.type() == TokenType::Error;
}