#include <cmath>
#include <iostream>
#include <random>
#include <string>

auto ask_user_for_integer(std::string prompt) -> int
{
    std::cout << prompt;
    auto n = std::string{};
    std::getline(std::cin, n);
    return std::stoi(n);
}

auto main() -> int
{
    std::random_device rd;
    std::uniform_int_distribution<int> d100(1, 100);
    auto const x = d100(rd);

    // std::cout<<x<<"\n";
    // zeby sprawdzic liczbe

    auto g = ask_user_for_integer("guess:  ");

    while (x != g) {
        if (g > x) {
            std::cout << "number too big!"
                      << "\n";
            g = ask_user_for_integer("guess:  ");
        } else if (g < x) {
            std::cout << "number too small!"
                      << "\n";
            g = ask_user_for_integer("guess:  ");
        }
    }

    std::cout << "just right!"
              << "\n";


    return 0;
}
