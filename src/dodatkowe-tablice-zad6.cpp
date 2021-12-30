#include <algorithm>
#include <iostream>
#include <string>

struct Kontakt {
    long int numer_telefonu;
    std::string nazwisko;
    int liczba_polaczen;

    /*
       Kontakt()
       {
           if (numer_telefonu > 999999999) {
               std::cout << "Podany numer jest za długi" << std::endl;
           } else if (numer_telefonu <= 99999999) {
               std::cout << "Podany numer jest za krotki" << std::endl;
           }
       }
   */
};

void dodaj(Kontakt*& k,
           unsigned int& n,
           const long int& nr,
           const std::string& na,
           const int& l)
{
    bool t;
    for (unsigned i = 0; i < n; i++) {
        if (k[i].numer_telefonu == nr) {
            std::cout << "Istnieje już kontakt o takim numerze" << std::endl;
            t = false;
            break;
        }
    }

    if (t) {
        Kontakt* new_k = new Kontakt[n + 1];
        std::copy(k, k + n, new_k);
        new_k[n++] = {nr, na, l};

        delete[] k;
        k = new_k;
    }
}


void wypisz(Kontakt k[], unsigned int n)
{
    for (unsigned int i = 0; i < n; i++) {
        std::cout << k[i].numer_telefonu << " " << k[i].nazwisko << " "
                  << k[i].liczba_polaczen << std::endl;
    }
}

void szukaj(Kontakt k[], unsigned int n, const long int& nr)
{
    bool t;
    unsigned int i;
    for (i = 0; i < n; i++) {
        if (nr == k[i].numer_telefonu) {
            t = true;
            break;
        } else {
            t = false;
        }
    }

    if (t == true) {
        std::cout << k[i].numer_telefonu << " " << k[i].nazwisko << " "
                  << k[i].liczba_polaczen << std::endl;
    } else if (t == false) {
        std::cout << "Podanego numeru nie ma w ksiazce" << std::endl;
    }
}


void usun(Kontakt*& k, unsigned int& n, const long int& nr)
{
    bool t;
    unsigned int i;
    for (i = 0; i < n; i++) {
        if (nr == k[i].numer_telefonu) {
            t = true;
            break;
        } else {
            t = false;
        }
    }

    if (t == true) {
        for (unsigned int j = i; j < n - 1; j++) {
            k[j] = k[j + 1];
        }

        Kontakt* new_k = new Kontakt[n - 1];
        n--;
        std::copy(k, k + n, new_k);

        delete[] k;
        k = new_k;

    } else if (t == false) {
        std::cout << "Podanego numeru nie ma w ksiazce" << std::endl;
    }
}

void polacz(Kontakt k[], unsigned int n, const std::string& naz)
{
    bool t;
    unsigned int i;
    for (i = 0; i < n; i++) {
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
    unsigned int n   = 0, a;
    Kontakt* ksiazka = nullptr;
    long int nr;
    std::string naz;

    while (a != 0) {
        std::cout << "Co chcesz zrobić?\n 1 - szukaj numeru, 2 - dodaj "
                     "numer, 3 - usuń numer, 4 - połącz z kontaktem, 5 - "
                     "wypisz numery, 0 - wyjdź"
                  << std::endl;
        std::cin >> a;

        switch (a) {
        case 1:
            std::cout << "Podaj numer: ";
            std::cin >> nr;

            szukaj(ksiazka, n, nr);
            break;

        case 2:
            std::cout << "Podaj numer do dodania: ";
            std::cin >> nr;
            std::cout << std::endl;
            std::cout << "Podaj nazwisko: ";
            std::cin >> naz;
            std::cout << std::endl;

            dodaj(ksiazka, n, nr, naz, 0);

            break;

        case 3:
            std::cout << "Podaj numer do usuniecia: ";
            std::cin >> nr;

            usun(ksiazka, n, nr);

            break;

        case 4:
            std::cout << "Podaj nazwisko do wyszukania: ";
            std::cin >> naz;

            polacz(ksiazka, n, naz);

            break;

        case 5:
            wypisz(ksiazka, n);
            break;
        }
    }


    delete[] ksiazka;
    return 0;
}
