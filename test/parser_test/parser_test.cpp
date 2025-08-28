#include <assert.h>
#include <iostream>
#include <cmath>

#include "parser/lexer.hpp"
#include "parser/parser.hpp"

constexpr FloatT EPSILON = 0.0001;

int main()
{

    {
        std::string input = "2 + 2 * 5";
        Lexer lexer(input);

        Tokens::Token current = lexer.next().curr();
        assert(current.type() == Tokens::Type::Literal);
        assert(current.value() == 2);

        current = lexer.next().curr();
        assert(current.type() == Tokens::Type::Addition);

        current = lexer.next().curr();
        assert(current.type() == Tokens::Type::Literal);
        assert(current.value() == 2);

        current = lexer.next().curr();
        assert(current.type() == Tokens::Type::Multiplication);

        current = lexer.next().curr();
        assert(current.type() == Tokens::Type::Literal);
        assert(current.value() == 5);

        current = lexer.next().curr();
        assert(current.type() == Tokens::Type::EndOfFile);
    }

    std::cout << "Test 1 passed(Lexer: simple expression)." << std::endl;

    {
        std::string input = "2 +4 * 5 * 3 + 0 ";
        Lexer lexer(input);

        Tokens::Token current = lexer.next().curr();
        assert(current.type() == Tokens::Type::Literal);
        assert(current.value() == 2);

        current = lexer.next().curr();
        assert(current.type() == Tokens::Type::Addition);

        current = lexer.next().curr();
        assert(current.type() == Tokens::Type::Literal);
        assert(current.value() == 4);

        current = lexer.next().curr();
        assert(current.type() == Tokens::Type::Multiplication);

        current = lexer.next().curr();
        assert(current.type() == Tokens::Type::Literal);
        assert(current.value() == 5);

        current = lexer.next().curr();
        assert(current.type() == Tokens::Type::Multiplication);

        current = lexer.next().curr();
        assert(current.type() == Tokens::Type::Literal);
        assert(current.value() == 3);

        current = lexer.next().curr();
        assert(current.type() == Tokens::Type::Addition);

        current = lexer.next().curr();
        assert(current.type() == Tokens::Type::Literal);
        assert(current.value() == 0);

        current = lexer.next().curr();
        assert(current.type() == Tokens::Type::EndOfFile);
    }

    std::cout << "Test 2 passed(Lexer: long expression)." << std::endl;

    {
        std::string input = "2";
        Lexer lexer(input);

        Tokens::Token current = lexer.next().curr();
        assert(current.type() == Tokens::Type::Literal);

        current = lexer.next().curr();
        assert(current.type() == Tokens::Type::EndOfFile);
    }

    std::cout << "Test 3 passed(Lexer: Single literal)." << std::endl;

    {
        std::string input = "a2";
        Lexer lexer(input);

        Tokens::Token current = lexer.next().curr();
        assert(current.type() == Tokens::Type::Error);

        // current = lexer.next().curr();
        // assert(current.type() == Tokens::Type::Literal);

        // current = lexer.next().curr();
        // assert(current.type() == Tokens::Type::EndOfFile);
    }

    std::cout << "Test 4 passed(Lexer: invalueid char)." << std::endl;

    {
        Parser p("2 + 2");
        assert(p.parse()->eval() == 4);

        p.setInputStr("11 + 74/2");
        assert(p.parse()->eval() == 48);

        p.setInputStr("1 + 0");
        assert(p.parse()->eval() == 1);

        p.setInputStr("9");
        assert(p.parse()->eval() == 9);

        // p.setInputStr("0 +");
        // assert(p.parse()->eval() == 0);

        p.setInputStr("9/2 + 0");
        assert(p.parse()->eval() == 4.5);

        p.setInputStr("9.2 + 0.1");
        assert(std::abs(p.parse()->eval() - 9.3) < EPSILON);
        // Fails with std::numeric_limits<FloatT>::epsilon()

        p.setInputStr("002 + 01");
        assert(p.parse()->eval() == 3);

        p.setInputStr("2+2*2");
        assert(p.parse()->eval() == 6);

        p.setInputStr("(2+2)*2");
        assert(p.parse()->eval() == 8);

        p.setInputStr("((2+2)*2)");
        assert(p.parse()->eval() == 8);

        p.setInputStr("((2+2)*(2))");
        assert(p.parse()->eval() == 8);

        p.setInputStr("((2+2)*(2))*3");
        assert(p.parse()->eval() == 24);

        p.setInputStr("(((2+2)*(2))*(3))");
        assert(p.parse()->eval() == 24);

        p.setInputStr("(2-4)*5");
        assert(p.parse()->eval() == -10);

        p.setInputStr("(6*4)  - 3");
        assert(p.parse()->eval() == 21);

        p.setInputStr("1  - 3 + 2");
        assert(p.parse()->eval() == 0);

        p.setInputStr("(6*4)  - 3 + (2-4)*5");
        assert(p.parse()->eval() == 11);

        p.setInputStr("((1-1)*5)+   (6*4)  - 3 + (2-4)*5");
        assert(p.parse()->eval() == 24. - 3. - 10.);
    }

    std::cout << "Test 5 passed(Parser)." << std::endl;

    {
        Parser p("2 + ");
        assert(p.parse() == nullptr);

        p.setInputStr("2 + -");
        assert(p.parse() == nullptr);

        p.setInputStr(" + -");
        assert(p.parse() == nullptr);

        p.setInputStr("(2");
        assert(p.parse() == nullptr);

        p.setInputStr("2)");
        assert(p.parse() == nullptr);

        p.setInputStr("()");
        assert(p.parse() == nullptr);

        p.setInputStr("3 + 2.");
        assert(p.parse() != nullptr);
    }

    std::cout << "Test 5 passed(Parser exceptions)." << std::endl;

    {
        Parser p("2 +++++++++++++++++++++++++++++++++ 12");
        assert(p.parse()->eval() == 14);

        p.setInputStr("2 +++--- 12");
        assert(p.parse()->eval() == -10);

        p.setInputStr("--- 12");
        assert(p.parse()->eval() == -12);

        p.setInputStr("---+12");
        assert(p.parse()->eval() == -12);

        p.setInputStr("12+-(4 + 0000000001)");
        assert(p.parse()->eval() == 7);

        p.setInputStr("(-3) + -2 + 2");
        assert(p.parse()->eval() == -3);

        p.setInputStr("--(4 + -(3 + 2 - 12))");
        assert(p.parse()->eval() == 11);
    }

    return 0;
}
