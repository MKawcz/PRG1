#include <iostream>
#include <string>

auto main(int argc, char* argv[]) -> int
{
    auto const password = std::string{argv[1]};
    auto password2      = std::string{};

    if (argc > 2) {
        std::cout << "Enter only one argument!"
                  << "\n";
    } else {
        do {
            std::cout << "password: ";
            std::getline(std::cin, password2);
        } while (password != password2);

        std::cout << "ok!"
                  << "\n";
    }
    return 0;
}
