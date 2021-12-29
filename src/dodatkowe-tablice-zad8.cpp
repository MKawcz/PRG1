#include <iostream>
#include <string>


struct Trojkat {
    int a;
    int b;
    int c;

    int najwieksza_kw()
    {
        int n = a;
        if (n < b)
            n = b;
        if (n < c)
            n = c;

        return n * n;
    }

    int pozostale_kw()
    {
        int n = a;
        int p = b * b + c * c;
        if (n < b) {
            n = b;
            p = a * a + c * c;
        }
        if (n < c) {
            n = c;
            p = a * a + b * b;
        }

        return p;
    }

    void sprawdz()
    {
        if ((a >= b + c) || (c >= b + a) || (c >= a + c)) {
            std::cout << "Nie mozna stworzyc takiego trojkata" << std::endl;
        } else if (najwieksza_kw() > pozostale_kw()) {
            std::cout << "Trojkat jest rozwartokatny" << std::endl;
        } else if (najwieksza_kw() < pozostale_kw()) {
            std::cout << "Trojkat jest ostrokatny" << std::endl;
        } else {
            std::cout << "Trojkat jest prostokatny" << std::endl;
        }
    }
};

auto main() -> int
{
    Trojkat t1 = {2, 3, 6};
    Trojkat t2 = {5, 4, 3};
    Trojkat t3 = {2, 4, 1};
    Trojkat t4 = {5, 7, 8};

    t1.sprawdz();
    t2.sprawdz();
    t3.sprawdz();
    t4.sprawdz();

    return 0;
}
