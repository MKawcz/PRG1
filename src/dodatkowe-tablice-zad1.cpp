
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
    char tab[3][3];

    std::cout << "Gracz 1: gdzie wstawic kolko? "
              << "\n";
    auto const a = ask_user_for_integer("rzad: ");
    auto const b = ask_user_for_integer("kolumna: ");

    t[a][b];

    std::cout << "Gracz 2: gdzie wstawic krzyzyk? "
              << "\n";
    auto const c = ask_user_for_integer("rzad: ");
    auto const d = ask_user_for_integer("kolumna: ");

    t[c][d];


    return 0;
}
