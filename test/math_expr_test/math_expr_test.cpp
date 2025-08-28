#include <cassert>

#include <math_expr/expression.hpp>
#include <math_expr/literal.hpp>
#include <math_expr/addition.hpp>
#include <math_expr/multiplication.hpp>
#include <math_expr/unary_subtraction.hpp>

int main()
{
    {
        Literal *lhs = new Literal(3);
        Literal *rhs = new Literal(5);
    
        assert(lhs->eval() == 3.);
        assert(rhs->eval() == 5.);
    
        Addition *all = new Addition(std::make_unique<Literal>(3.), std::make_unique<Literal>(5.));
        assert(all->eval() == 8.);
    }

    {
        UnarySubtraction *lhs = new UnarySubtraction(std::make_unique<Literal>(3));

        assert(lhs->eval() == -3);

        Addition *result = new Addition(std::make_unique<UnarySubtraction>(
                            std::make_unique<Literal>(3)), 
                            std::make_unique<Literal>(2));

        assert(result->eval() == -1);
    }

    return 0;
}