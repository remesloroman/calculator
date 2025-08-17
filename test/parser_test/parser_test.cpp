#include <assert.h>
#include <iostream>

#include "parser/lexer.hpp"

int main () {

    {
        std::string input = "2 + 2 * 5";
        Lexer lexer(input);

        Token current = lexer.next();
        assert(current.type() == TokenType::Literal);
        assert(current.val() == 2);

        current = lexer.next();
        assert(current.type() == TokenType::Addition);

        current = lexer.next();
        assert(current.type() == TokenType::Literal);
        assert(current.val() == 2);

        current = lexer.next();
        assert(current.type() == TokenType::Multiplication);

        current = lexer.next();
        assert(current.type() == TokenType::Literal);
        assert(current.val() == 5);

        current = lexer.next();
        assert(current.type() == TokenType::EndOfFile);
    }

    std::cout << "Test 1 passed.\n";

    {
        std::string input = "2 +4 * 5 * 3 + 0 ";
        Lexer lexer(input);

        Token current = lexer.next();
        assert(current.type() == TokenType::Literal);
        assert(current.val() == 2);

        current = lexer.next();
        assert(current.type() == TokenType::Addition);

        current = lexer.next();
        assert(current.type() == TokenType::Literal);
        assert(current.val() == 4);

        current = lexer.next();
        assert(current.type() == TokenType::Multiplication);

        current = lexer.next();
        assert(current.type() == TokenType::Literal);
        assert(current.val() == 5);

        current = lexer.next();
        assert(current.type() == TokenType::Multiplication);

        current = lexer.next();
        assert(current.type() == TokenType::Literal);
        assert(current.val() == 3);

        current = lexer.next();
        assert(current.type() == TokenType::Addition);

        current = lexer.next();
        assert(current.type() == TokenType::Literal);
        assert(current.val() == 0);

        current = lexer.next();
        assert(current.type() == TokenType::EndOfFile);
    }

    std::cout << "Test 2 passed.\n";

    {
        std::string input = "2";
        Lexer lexer(input);

        Token current = lexer.next();
        assert(current.type() == TokenType::Literal);

        current = lexer.next();
        assert(current.type() == TokenType::EndOfFile);
    }

    std::cout << "Test 3 passed.\n";

    {
        std::string input = "a2";
        Lexer lexer(input);

        Token current = lexer.next();
        assert(current.type() == TokenType::Error);

        current = lexer.next();
        assert(current.type() == TokenType::Literal);

        current = lexer.next();
        assert(current.type() == TokenType::EndOfFile);
    }

    std::cout << "Test 4 passed.\n";

    return 0;
}
