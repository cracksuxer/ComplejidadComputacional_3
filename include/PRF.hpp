#include <iostream>
#include "../include/termcolor.hpp"

class PRF
{
private:
    inline static int CALL_COUNT = 0;
public:
    static int Z(int, int depth = 0) noexcept;
    static int S(int, int depth = 0) noexcept;
    static int P(int, int depth = 0) noexcept;

    static int addition(int x, int y, int depth = 0);
    static int multiplication(int x, int y, int depth = 0);
    static int potence(int x, int y, int depth = 0);
    static int division(int x, int y, int depth = 0);
    static int factorial(int x, int depth = 0);

    static void reset_count();
    static int get_count();
};