#include <cstdlib>
#include <iostream>
#include <random>
#include <string>

auto main(int argc, char* argv[]) -> int
{
    int tab[5000];
    int i;
    int n = 0;

    for (i = 1; i < argc; i++) {
        std::random_device rd;
        std::uniform_int_distribution<int> d10(1, 10);
        auto const z = d10(rd);

        tab[i] = z;
        std::cout << tab[i] << " ";
    }
    std::cout << std::endl;

    for (auto j = 1; j < argc; j++) {
        auto x = std::stoi(argv[j]);

        if (x == tab[j]) {
            n++;
        }
    }

    std::cout << "trafiles " << n << " z " << argc - 1 << std::endl;

    return 0;
}
