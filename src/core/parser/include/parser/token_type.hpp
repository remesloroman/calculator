#pragma once

enum class TokenType
{
    EndOfFile,
    Error,

    Literal,
    Addition,
    Multiplication,
    Subtraction,
    Division,

    LeftParen,
    RightParen,

};
