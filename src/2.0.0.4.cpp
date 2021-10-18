
#include <iostream>
#include <string>

auto main(int argc, char* argv[]) -> int
{
    auto liczba = std::stoi(argv[1]);

    if (argc > 2) {
        std::cout << "Enter one number!"
                  << "\n";
    } else {
        for (int i = 2; i * i < liczba; i++) {
            if (liczba % i == 0) {
                if (i == liczba) {
                    std::cout << "jest pierwsza!"
                              << "\n";
                    std::cout << "petla wykonala sie " << i << " razy"
                              << std::endl;

                } else {
                    std::cout << "nie jest pierwsza!"
                              << "\n";
                    std::cout << "petla wykonala sie " << i << " razy"
                              << std::endl;
                }
            }
            break;
        }
    }

    return 0;
}
