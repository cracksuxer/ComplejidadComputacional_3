#include "../include/PRF.hpp"
#include <tuple>

using std::literals::string_literals::operator""s;

auto parseParams(int argc, char* argv[]) -> std::tuple<int, int>
{
    if (argc != 3) return std::make_tuple(INT_MAX, INT_MAX);

    int x{0}, y{0};

    try 
    {
        x = std::stoi(argv[1]);
        y = std::stoi(argv[2]);
    } catch (const std::invalid_argument&) 
    {
        return std::make_tuple(INT_MAX, INT_MAX);
    }

    return std::make_tuple(x, y);
}

int main(int argc, char* argv[]) 
{
    auto [x, y] = parseParams(argc, argv);

    if (x == INT_MAX || y == INT_MAX) 
    {
        std::cout << "> Select two integers to perform the operations\n";
        std::cout << "> X: ";
        std::cin >> x;
        std::cout << "> Y: ";
        std::cin >> y;
    }

    PRF::reset_count();

    try
    {
        int result = PRF::addition(x, y);
        std::cout << termcolor::green << "\n - Addition: " << termcolor::reset << result << "\n";
        std::cout << " - Number of calls: " << PRF::get_count() << "\n\n";

        PRF::reset_count();

        result = PRF::multiplication(x, y);
        std::cout << termcolor::green << "\n - Multiplication: " << termcolor::reset << result << "\n";
        std::cout << " - Number of calls: " << PRF::get_count() << "\n\n";

        PRF::reset_count();

        result = PRF::potence(x, y);
        std::cout << termcolor::green << "\n - Potence: " << result << termcolor::reset << "\n";
        std::cout << " - Number of calls: " << PRF::get_count() << "\n\n";
        
        PRF::reset_count();

        result = PRF::division(x, y);
        std::cout << termcolor::green << "\n - Division: " << result << termcolor::reset << "\n";
        std::cout << " - Number of calls: " << PRF::get_count() << "\n\n";

        PRF::reset_count();
        result = PRF::factorial(x);
        std::cout << termcolor::green << "\n - Factorial: " << result << termcolor::reset << "\n";
        std::cout << " - Number of calls: " << PRF::get_count() << "\n\n";

        PRF::reset_count();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}