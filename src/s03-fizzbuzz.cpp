#include <iostream>
#include <string>

auto main(int argc, char* argv[]) -> int
{
    auto const liczba = std::stoi(argv[1]);

    if (argc > 2) {
        std::cout << "Enter one number!"
                  << "\n";
    } else {
        for (auto i = 1; i <= liczba; i++) {
            if ((i % 5 == 0) && (i % 3 == 0)) {
                std::cout << i << " FizzBuzz"
                          << "\n";
            } else if (i % 3 == 0) {
                std::cout << i << " Fizz"
                          << "\n";
            } else if (i % 5 == 0) {
                std::cout << i << " Buzz"
                          << "\n";
            } else {
                std::cout << i << "\n";
            }
        }
    }

    return 0;
}
