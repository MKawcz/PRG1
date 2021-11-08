#include <iostream>
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
    auto const a = ask_user_for_integer("Podaj wysokosc: ");

    for (auto l = 0; l < a * 2 - 3; l++) {
        std::cout << "*";
    }

    std::cout << std::endl;

    for (auto i = 0; i < a - 2; i++) {
        for (auto j = 0; j < a - 2 - i; j++) {
            std::cout << "*";
        }
        for (auto k = 0; k < i * 2 + 1; k++) {
            std::cout << " ";
        }
        for (auto j = 0; j < a - 2 - i; j++) {
            std::cout << "*";
        }

        std::cout << std::endl;
    }

    for (auto m = 0; m < a * 2 - 3; m++) {
        std::cout << "*";
    }
    std::cout << std::endl;

    return 0;
}
