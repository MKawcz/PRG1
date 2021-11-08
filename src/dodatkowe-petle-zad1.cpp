
#include <iostream>
#include <string>

auto main(int argc, char* argv[]) -> int
{
    auto liczba = std::stoi(argv[1]);

    if (argc > 2) {
        std::cout << "Enter one number!"
                  << "\n";
    } else {
        int i;

        if (liczba < 2) {
            std::cout << "nie jest pierwsza!"
                      << "\n";
            std::cout << "petla wykonala sie 0 razy" << std::endl;
            return 0;  // program zwraca wartosc 0 wiec skompilował sie
                       // pomyslnie
        }
        for (i = 2; i * i <= liczba;
             i++) {  // i*i poniewaz jesli podamy np liczbe 7 to petla zakonczy
                     // sie na liczbie 3, przez co nie dojdzie do tej 7 i nie
                     // znajdzie liczby podzielnej i zadziala warunek if
            if (liczba % i == 0) {  // a jesli wyciagniemy pierwiastek z jakiejs
                                    // liczby i usadowimy jego wartosc posrod
                                    // dzielnikow danej liczby to zawsze bedzie
                                    // mial on tyle samo dzielnikow po lewej i
                                    // prawej stronie
                std::cout << "nie jest pierwsza!"  // std::cout<<i<<std::endl;
                          << "\n";
                std::cout << "petla wykonala sie " << i - 1
                          << " razy"  // i-1 poniewaz petle zaczynamy od 2 wiec
                                      // mamy o 1 wiecej na starcie
                          << std::endl;
                return 0;
            }
        }
        std::cout << "jest pierwsza!"  // nie mozemy dac tego w else poniewaz
                                       // jesli podamy np 9 to przy i=2 po
                                       // przejściu prze pokaze jest pierwsza
                  << "\n";
        std::cout << "petla wykonala sie " << i - 1 << " razy" << std::endl;
    }

    return 0;
}
