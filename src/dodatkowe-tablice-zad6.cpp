#include <iostream>
#include <string>


struct Kontakt {
    int numer_telefonu;
    std::string nazwisko;
    int liczba_poloczen;

    Kontak(int nr, std::string naz, int lp, )
    {
        numer_telefonu  = nr;
        nazwisko        = naz;
        liczba_poloczen = lp;
    }

    void wypisz(int k[], int lt, int lp)
    {
        for (int i = 0; i <= lt; i++) {
            std::cout << k[i] << endl;
        }
    }

    void dodaj(int nr, std::string naz, int lp)
    {
        numer_telefonu  = nr;
        nazwisko        = naz;
        liczba_poloczen = lp;
    }
};

auto main() -> int
{
    int ksiazka[50000];
    int a;
    int liczba_tel;


    while (a != 0) {
        switch (a) {
        case 1:

            break;

        case 2:

            break;

        case 3:

            break;

        case 4:

            break;

        case 5:

            break;

        default:
            std::cout << "Co chcesz zrobić?\n 1 - szukaj numeru, 2 - dodaj "
                         "numer, 3 - usuń numer, 4 - połącz z kontaktem, 5 - "
                         "wypisz numery, 0 - wyjdź";
            cin >> a;
            break;
        }
    }


    return 0;
}
