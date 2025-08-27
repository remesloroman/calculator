#include "parser/lexer.hpp"

#include "parser/token_type.hpp"
#include "parser/token.hpp"

Lexer::Lexer(std::string input_str) : input_stream_(std::move(input_str)), curr_(Tokens::Type::None),
                                      next_(getTokenFromStream())
{
}

void Lexer::setInputStr(std::string input_str)
{
    input_stream_.clear();
    input_stream_.str(std::move(input_str));
    curr_ = Tokens::Token{Tokens::Type::None};
    next_ = getTokenFromStream();
}

const Tokens::Token& Lexer::peek() const
{
    return next_;
}

const Tokens::Token& Lexer::curr() const
{
    return curr_;
}

Tokens::Token Lexer::getTokenFromStream()
{
    input_stream_ >> std::ws;
    if (input_stream_.eof())
    {
        return Tokens::Token{Tokens::Type::EndOfFile};
    }

    char character = input_stream_.peek();
    if (std::isdigit(static_cast<unsigned char>(character)))
    {
        FloatT value = 0.0;
        if (!(input_stream_ >> value))
            return Tokens::Token{Tokens::Type::Error};

        return Tokens::Token{value};
    }

    input_stream_.get();
    return Tokens::Token{Tokens::typeFromChar(character)};
}

Lexer& Lexer::next()
{
    if (!end() && !error())
    {
        curr_ = next_;
        next_ = getTokenFromStream();
    }

    return *this;
}

bool Lexer::end() const
{
    return curr_.type() == Tokens::Type::EndOfFile;
}

bool Lexer::error() const
{
    return curr_.type() == Tokens::Type::Error;
}
