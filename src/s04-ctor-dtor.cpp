#include <iostream>
#include <string>


struct Destr {
    Destr(std::string w)
    {
        wartosc = w;
    }

    std::string wartosc;

    ~Destr()
    {
        std::cout << wartosc << " DESTRUCTION!" << std::endl;
    }
};

auto main() -> int
{
    auto slowo = Destr("mikolaj");

    return 0;
}
