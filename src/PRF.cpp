#include "PRF.hpp"

int PRF::Z(int n, int depth) noexcept 
{
    CALL_COUNT++;

#ifdef DEBUG
    for (int i = 0; i < depth; ++i) std::cout << "| ";
    std::cout << termcolor::red << "Z(" << n << ")" << termcolor::reset << std::endl;
#endif 

    return 0;
}

int PRF::S(int n, int depth) noexcept 
{
    CALL_COUNT++;

#ifdef DEBUG
    for (int i = 0; i < depth; ++i) std::cout << "| ";
    std::cout << termcolor::yellow << "S(" << n << ")" << termcolor::reset << std::endl;
#endif

    return n + 1;
}

int PRF::P(int n, int depth) noexcept 
{
    CALL_COUNT++;

#ifdef DEBUG
    for (int i = 0; i < depth; ++i) std::cout << "| ";
    std::cout << termcolor::blue << "P(" << n << ")" << termcolor::reset << std::endl;
#endif

    return n;
}

int PRF::addition(int x, int y, int depth) 
{
    CALL_COUNT++;

#ifdef DEBUG
    for (int i = 0; i < depth; ++i) std::cout << "| ";
    std::cout << termcolor::magenta << "addition(" << x << ", " << y << ")" << termcolor::reset << std::endl;
#endif

    if (y == 0) return x;
    return S(addition(x, y - 1, depth + 1), depth);
}

int PRF::multiplication(int x, int y, int depth) 
{
    CALL_COUNT++;

#ifdef DEBUG
    for (int i = 0; i < depth; ++i) std::cout << "| ";
    std::cout << termcolor::cyan << "multiplication(" << x << ", " << y << ")" << termcolor::reset << std::endl;
#endif

    if (y == 0) return Z(x, depth);
    return addition(x, multiplication(x, y - 1, depth));
}

int PRF::potence(int x, int y, int depth) 
{
    CALL_COUNT++;

#ifdef DEBUG
    for (int i = 0; i < depth; ++i) std::cout << "| ";
    std::cout << termcolor::white << "potence(" << x << ", " << y << ")" << termcolor::reset << std::endl;
#endif

    if (y == 0) return S(Z(0, depth - 1), depth + 1);
    return multiplication(x, potence(x, y - 1, depth + 1));
}

int PRF::division(int x, int y, int depth)
{
    CALL_COUNT++;

#ifdef DEBUG
    for (int i = 0; i < depth; ++i) std::cout << "| ";
    std::cout << termcolor::bright_blue << "division(" << x << ", " << y << ")" << termcolor::reset << std::endl; 
#endif

    if (x < y) return Z(0, depth);
    return S(division(x - y, y, depth + 1), depth);
}

int PRF::factorial(int x, int depth)
{
    CALL_COUNT++;

#ifdef DEBUG
    for (int i = 0; i < depth; ++i) std::cout << "| ";
    std::cout << termcolor::bright_red << "factorial(" << x << ")" << termcolor::reset << std::endl;
#endif

    if (x == 0) return S(Z(0, depth), depth);
    return multiplication(x, factorial(x - 1, depth + 1));
}

void PRF::reset_count() 
{
    CALL_COUNT = 0;
}

int PRF::get_count() 
{
    return CALL_COUNT;
}