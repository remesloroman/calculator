#pragma once

#include <string>
#include <optional>

#include "parser/parser.hpp"
#include "../../alias.hpp"

class CalculatorBackend{
public:
    CalculatorBackend(std::string input_string = "");

    std::optional<FloatT> eval();

    void setInputString(std::string input_string);

private:
    Parser parser_;
};