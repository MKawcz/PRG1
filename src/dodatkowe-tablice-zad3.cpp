#include <iostream>
#include <string>


struct Samochod {
    std::string marka;
    std::string model;
    int rok_produkcji;
    int przebieg;
    int cena_wyjsciowa;
    int cena_koncowa;

    Samochod(std::string mr, std::string md, int rp, int pr)
    {
        marka         = mr;
        model         = md;
        rok_produkcji = rp;
        przebieg      = pr;
    }

    void ustaw_cene_wyjsciowa(int a)
    {
        cena_wyjsciowa = a;
    }

    auto oblicz_cene_koncowa() -> int
    {
        return cena_wyjsciowa - 10000 * (2021 - rok_produkcji) - 3 * (przebieg);
    }
};

auto main() -> int
{
    auto s1 = Samochod("Audi", "a6", 2015, 3000);
    auto s2 = Samochod("Peugeot", "1007", 2012, 6000);
    s1.ustaw_cene_wyjsciowa(330000);
    s2.ustaw_cene_wyjsciowa(200000);
    std::cout << s1.oblicz_cene_koncowa() << std::endl;
    std::cout << s2.oblicz_cene_koncowa() << std::endl;

    return 0;
}
