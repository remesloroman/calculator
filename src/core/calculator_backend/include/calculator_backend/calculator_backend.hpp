#pragma once

#include <string>
#include <optional>

#include "parser/parser.hpp"
#include "alias/alias.hpp"

class CalculatorBackend
{
public:
    explicit CalculatorBackend(std::string input_string = "");

    std::optional<FloatT> eval();

    void setInputStr(std::string input_string);

private:
    Parser parser_;
};