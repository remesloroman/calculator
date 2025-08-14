#pragma once

#include <iostream>

#include "../alias.hpp"

class Expression{
public:
    friend std::ostream &operator<<(std::ostream &os, const Expression &expr);

    virtual std::ostream &print(std::ostream &os) const = 0;

    virtual FloatT eval() const = 0;

    virtual ~Expression() = default;

};

#include <memory>
using ExprPtr = std::unique_ptr<Expression>;