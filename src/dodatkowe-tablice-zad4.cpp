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

    int tab[5000];

    for(auto i=0; i<


return 0;
}
