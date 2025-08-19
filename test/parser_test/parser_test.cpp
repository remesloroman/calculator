#include <assert.h>
#include <iostream>
#include <cmath>

#include "parser/lexer.hpp"
#include "parser/parser.hpp"

constexpr FloatT EPSILON = 0.0001;

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

    std::cout << "Test 1 passed(Lexer: simple expression)." << std::endl;

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

    std::cout << "Test 2 passed(Lexer: long expression)." << std::endl;

    {
        std::string input = "2";
        Lexer lexer(input);

        Token current = lexer.next();
        assert(current.type() == TokenType::Literal);

        current = lexer.next();
        assert(current.type() == TokenType::EndOfFile);
    }

    std::cout << "Test 3 passed(Lexer: Single literal)." << std::endl;

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

    std::cout << "Test 4 passed(Lexer: invalid char)." << std::endl;

    {
        Parser p("2 + 2");
        assert(p.parse()->eval() == 4);

        p.setInputString("11 + 74/2");
        assert(p.parse()->eval() == 48);

        p.setInputString("1 + 0");
        assert(p.parse()->eval() == 1);

        p.setInputString("9");
        assert(p.parse()->eval() == 9);

        // p.setInputString("0 +");
        // assert(p.parse()->eval() == 0);

        p.setInputString("9/2 + 0");
        assert(p.parse()->eval() == 4.5);

        p.setInputString("9.2 + 0.1");
        assert(std::abs(p.parse()->eval() - 9.3) < EPSILON);
        // Fails with std::numeric_limits<FloatT>::epsilon()

        p.setInputString("002 + 01");
        assert(p.parse()->eval() == 3);        
    }
    
    std::cout << "Test 5 passed(Parser)." << std::endl;

    return 0;
}
