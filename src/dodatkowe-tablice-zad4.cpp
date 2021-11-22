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
    int tab[1000][1000];

    tab[0][0] = 1;
    tab[1][0] = 1;
    tab[1][1] = 1;

    for (auto i = 2; i < a; i++) {
        for (auto j = 0; j <= i; j++) {
            if (i == j) {
                tab[j][i] = 1;
            }

            if (j == 0) {
                tab[j][i] = 1;
            }

            tab[i][j] = tab[i - 1][j - 1] + tab[i - 1][j];
        }
    }


    for (auto k = 0; k < a; k++) {
        for (auto l = 0; l <= k; l++) {
            std::cout << tab[k][l] << " ";
        }
        std::cout << std::endl;
    }


    return 0;
}
