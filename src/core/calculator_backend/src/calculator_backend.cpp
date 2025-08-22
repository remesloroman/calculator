#include <utility>

#include "calculator_backend/calculator_backend.hpp"

CalculatorBackend::CalculatorBackend(std::string input_string) : parser_(std::move(input_string))
{
}

void CalculatorBackend::setInputString(std::string input_string){
    parser_.setInputString(std::move(input_string));
}

std::optional<FloatT> CalculatorBackend::eval(){
    if(ExprPtr ptr = parser_.parse(); ptr){
        return ptr->eval();
    }

    return std::nullopt;
}
