#include <iostream>
#include <string>


struct Kontakt {
    int numer_telefonu;
    std::string nazwisko;
    int liczba_polaczen;

    /* Kontakt(int nr, std::string naz, int lp)
     {
         numer_telefonu  = nr;
         nazwisko        = naz;
         liczba_polaczen = lp;
     }
     */
    void wypisz(Kontakt k[5000])
    {
        for (int i = 0; i < 5000; i++) {
            std::cout << k[i].numer_telefonu << " " << k[i].nazwisko << " "
                      << k[i].liczba_polaczen << std::endl;
        }
    }

    void szukaj(Kontakt k[5000], int n)
    {
        for (int i = 0; i < 5000; i++) {
            if (n == k[i].numer_telefonu) {
                std::cout << k[i].numer_telefonu << " " << k[i].nazwisko
                          << std::endl;
            } else {
                std::cout << "Podanego numeru nie ma w ksiazce" << std::endl;
            }
        }
    }

    void dodaj(Kontakt k[5000], int n, std::string na, int l)
    {
        bool t;
        for (int i = 0; i < 5000; i++) {
            if (n != k[i].numer_telefonu) {
                t = true;
            } else {
                t = false;
            }
        }

        if (t) {
            numer_telefonu  = n;
            nazwisko        = na;
            liczba_polaczen = l;
        } else {
            std::cout << "Istnieje już kontakt o takim numerze" << std::endl;
        }
    }

    void usun(Kontakt k[5000], int n)
    {
        for (int i = 0; i < 5000; i++) {
            if (n == k[i].numer_telefonu) {
                for (int j = i; j < 5000 - 1; j++)
                    k[i] = k[i + 1];
            } else {
                std::cout << "Podanego numeru nie ma w ksiazce" << std::endl;
            }
        }
    }

    void polacz(Kontakt k[5000], std::string n)
    {
        for (int i = 0; i < 5000; i++) {
            if (n == k[i].nazwisko) {
                k[i].liczba_polaczen++;
                std::cout << k[i].numer_telefonu << " " << k[i].nazwisko << " "
                          << k[i].liczba_polaczen << std::endl;
            } else {
                std::cout << "Podanego nazwiska nie ma w ksiazce" << std::endl;
            }
        }
    }
};

auto main() -> int
{
    Kontakt ksiazka[5000];
    int a, nr;
    std::string naz;
    int liczba_tel;


    while (a != 0) {
        switch (a) {
        case 1:
            std::cout << "Podaj numer: ";
            std::cin >> nr;

            ksiazka[5000].szukaj(ksiazka[5000], nr);
            break;

        case 2:
            std::cout << "Podaj numer: ";
            std::cin >> nr;
            std::cout << std::endl;
            std::cout << "Podaj nazwisko: ";
            std::cin >> naz;
            std::cout << std::endl;

            dodaj(ksiazka[5000], nr, naz, 0);

            break;

        case 3:
            std::cout << "Podaj numer: ";
            std::cin >> nr;

            usun(ksiazka[5000], nr);

            break;

        case 4:
            std::cout << "Podaj nazwisko: ";
            std::cin >> naz;

            polacz(ksiazka[5000], naz);

            break;

        case 5:
            wypisz(ksiazka[5000]);
            break;

        default:
            std::cout << "Co chcesz zrobić?\n 1 - szukaj numeru, 2 - dodaj "
                         "numer, 3 - usuń numer, 4 - połącz z kontaktem, 5 - "
                         "wypisz numery, 0 - wyjdź";
            std::cin >> a;
            break;
        }
    }


    return 0;
}
