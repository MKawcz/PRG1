#include <iostream>
#include <string>


struct Kontakt {
    long int numer_telefonu;
    std::string nazwisko;
    int liczba_polaczen;

    Kontakt()
    {
        if (numer_telefonu > 999999999) {
            std::cout << "Podany numer jest za długi" << std::endl;
        } else if (numer_telefonu < 100000000) {
            std::cout << "Podany numer jest za krotki" << std::endl;
        }
    }
};

void wypisz(Kontakt k[], int& n)
{
    for (int i = 0; i <= n; i++) {
        std::cout << k[i].numer_telefonu << " " << k[i].nazwisko << " "
                  << k[i].liczba_polaczen << std::endl;
    }
}

void szukaj(Kontakt k[], int& n, const long int& nr)
{
    bool t;
    int i;
    for (i = 0; i <= n; i++) {
        if (nr == k[i].numer_telefonu) {
            t = true;
            break;
        } else {
            t = false;
        }
    }

    if (t) {
        std::cout << k[i].numer_telefonu << " " << k[i].nazwisko << std::endl;
    } else {
        std::cout << "Podanego numeru nie ma w ksiazce" << std::endl;
    }
}

void dodaj(Kontakt k[],
           int& n,
           const long int& nr,
           const std::string& na,
           const int& l)
{
    bool t;
    for (int i = 0; i <= n; i++) {
        if (nr != k[i].numer_telefonu) {
            t = true;
        } else {
            t = false;
        }
    }

    if (t) {
        n++;
        k[n].numer_telefonu  = nr;
        k[n].nazwisko        = na;
        k[n].liczba_polaczen = l;
    } else {
        std::cout << "Istnieje już kontakt o takim numerze" << std::endl;
    }
}

void usun(Kontakt k[], int& n, const long int& nr)
{
    for (int i = 0; i <= n; i++) {
        if (nr == k[i].numer_telefonu) {
            for (int j = i; j < n; j++) {
                k[i] = k[i + 1];
            }
        }
        break;
    }

    std::cout << "Podanego numeru nie ma w ksiazce" << std::endl;
}

void polacz(Kontakt k[], int& n, const std::string& naz)
{
    bool t;
    int i;
    for (i = 0; i <= n; i++) {
        if (naz == k[i].nazwisko) {
            t = true;
            break;
        } else {
            t = false;
        }
    }

    if (t) {
        k[i].liczba_polaczen++;
        std::cout << k[i].numer_telefonu << " " << k[i].nazwisko << " "
                  << k[i].liczba_polaczen << std::endl;
    } else {
        std::cout << "Podanego nazwiska nie ma w ksiazce" << std::endl;
    }
}


auto main() -> int
{
    int n            = 0, a;
    Kontakt* ksiazka = new Kontakt[n];
    long int nr;
    std::string naz;


    while (a != 0) {
        switch (a) {
        case 1:
            std::cout << "Podaj numer: ";
            std::cin >> nr;

            szukaj(ksiazka, n, nr);
            break;

        case 2:
            std::cout << "Podaj numer: ";
            std::cin >> nr;
            std::cout << std::endl;
            std::cout << "Podaj nazwisko: ";
            std::cin >> naz;
            std::cout << std::endl;

            dodaj(ksiazka, n, nr, naz, 0);

            break;

        case 3:
            std::cout << "Podaj numer: ";
            std::cin >> nr;

            usun(ksiazka, n, nr);

            break;

        case 4:
            std::cout << "Podaj nazwisko: ";
            std::cin >> naz;

            polacz(ksiazka, n, naz);

            break;

        case 5:
            wypisz(ksiazka, n);
            break;

        default:
            std::cout << "Co chcesz zrobić?\n 1 - szukaj numeru, 2 - dodaj "
                         "numer, 3 - usuń numer, 4 - połącz z kontaktem, 5 - "
                         "wypisz numery, 0 - wyjdź"
                      << std::endl;
            std::cin >> a;
            break;
        }
    }

    delete[] ksiazka;
    return 0;
}
