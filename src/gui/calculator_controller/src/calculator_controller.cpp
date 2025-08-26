#include "calculator_controller/calculator_controller.hpp"

CalculatorController::CalculatorController(QObject *parent) 
    : QObject(parent) {}

void CalculatorController::setInputText(QString inputText) {
    if(input_text_ == inputText)
        return;

    input_text_ = inputText;
    emit inputTextChanged();
}

QString CalculatorController::inputText() {
    return input_text_;
}

void CalculatorController::appendText(QString symbol) {
    setInputText(input_text_ + symbol);
}

void CalculatorController::clear() {
    setInputText("");
}

void CalculatorController::calculate() {
    backend_.setInputString(input_text_.toStdString());

    QString result;

    try{
        result = QString::number(backend_.eval().value_or(0));
    } catch(const std::exception & e) {
        result = "Unexpected symbol";
    }

    setInputText(result);
}

void CalculatorController::processInput(QString symbol) {
    symbol = symbol.toLower();

    if(symbol == "c") {
        clear();
    } else if(symbol == "=") {
        if(!input_text_.isEmpty())
            calculate();
    } else {
        appendText(symbol);
    }
}