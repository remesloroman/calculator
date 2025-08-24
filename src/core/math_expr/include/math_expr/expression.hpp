#pragma once

#include <iostream>
#include <memory>

#include "alias/alias.hpp"

class Expression{
public:
    friend std::ostream &operator<<(std::ostream &os, const Expression &expr);

    virtual std::ostream &print(std::ostream &os) const = 0;

    virtual FloatT eval() const = 0;

    virtual ~Expression() = default;

};

using ExprPtr = std::unique_ptr<Expression>;