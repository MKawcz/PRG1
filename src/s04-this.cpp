#include <iostream>
#include <string>


struct liczby {
    int x;

    void pokaz_wartosc()
    {
        std::cout << x << std::endl;
    }

    liczby(int x)
    {
        this->x = x;
    }
};

auto main() -> int
{
    auto liczba = liczby(25);

    liczba.pokaz_wartosc();

    std::cout << &liczba << std::endl;

    return 0;
}
