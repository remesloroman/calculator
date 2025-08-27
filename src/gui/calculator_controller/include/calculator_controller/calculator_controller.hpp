#pragma once

#include <QObject>
#include "calculator_backend/calculator_backend.hpp"

class CalculatorController : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString inputText READ inputText WRITE setInputText NOTIFY inputTextChanged)

public:
    CalculatorController(QObject *parent = nullptr);

    Q_INVOKABLE void setInputText(QString inputText);

    QString inputText();

    void appendText(QString symbol);

    void clear();

    void calculate();

    Q_INVOKABLE void processInput(QString symbol);

signals:
    void inputTextChanged();

private:
    QString input_text_;
    CalculatorBackend backend_;
};