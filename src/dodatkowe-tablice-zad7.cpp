#include <algorithm>
#include <iostream>
#include <string>

struct Data {
    int dzien;
    int miesiac;
    int rok;
    /*
        Data(int d, int m, int r) : dzien{d}, miesiac{m}, rok{r}
        {
            if (miesiac == 2) {
                if (dzien > 28) {
                    dzien = dzien - 28;
                    miesiac++;
                } else if (dzien < 1) {
                    dzien = 31 + dzien;
                    miesiac--;
                }
            } else if (miesiac == 8 || miesiac == 1) {
                if (dzien > 31) {
                    dzien = dzien - 31;
                    miesiac++;
                } else if (dzien < 1) {
                    dzien = 31 + dzien;
                    miesiac--;
                }

            } else if (miesiac == 3) {
                if (dzien > 31) {
                    dzien = dzien - 31;
                    miesiac++;
                } else if (dzien < 1) {
                    dzien = 28 + dzien;
                    miesiac--;
                }
            } else if (miesiac == 5 || miesiac == 7 || miesiac == 10
                       || miesiac == 12) {
                if (dzien > 31) {
                    dzien = dzien - 31;
                    miesiac++;
                } else if (dzien < 1) {
                    dzien = 30 + dzien;
                    miesiac--;
                }
            } else if (miesiac == 4 || miesiac == 6 || miesiac == 9
                       || miesiac == 11) {
                if (dzien > 30) {
                    dzien = dzien - 30;
                    miesiac++;
                } else if (dzien < 1) {
                    dzien = 31 + dzien;
                    miesiac--;
                }
            }

            if (miesiac > 12) {
                miesiac = miesiac - 12;
                rok++;
            } else if (miesiac < 1) {
                miesiac = 12 + miesiac;
                rok--;
            }
        }
    */
};

struct Pacjent {
    std::string login;
    std::string haslo;
    std::string nazwisko;
    unsigned int l = 0;
    Data* daty     = nullptr;

    delete[] daty;
};
/*
    void wyloguj()
    {

    }
*/
void wypisz(Data d[], unsigned int l)
{
    for (unsigned int i = 0; i < l; i++) {
        std::cout << d[i].dzien << "." << d[i].miesiac << "." << d[i].rok
                  << std::endl;
    }
}

bool czyMoge(Data d[], Data d2[], unsigned int l)
{
    if (l > 0) {
        return true;
        std::cout << "Mozesz sie juz zaszczepic" << std::endl;
    } else if (l == 0) {
        if (((d[0].rok == d2[0].rok) && (d[0].miesiac + 1 == d2[0].miesiac)
             && (d[0].dzien < d2[0].dzien))
            || ((d[0].rok == d2[0].rok) && (d[0].miesiac + 1 < d2[0].miesiac))
            || ((d[0].rok + 1 == d2[0].rok) && (d[0].miesiac == 12)
                && (d2[0].miesiac = 1) && (d[0].dzien < d2[0].dzien))
            || ((d[0].rok + 1 == d2[0].rok) && (d[0].miesiac == 12)
                && (d2[0].miesiac > 1))
            || (d[0].rok < d2[0].rok)) {
            return true;
            std::cout << "Mozesz sie juz zaszczepic" << std::endl;

        } else {
            return false;
            std::cout << "Nie mozesz sie jeszcze zaszczepic" << std::endl;
        }
    } else {
        if (((d[0].rok == d2[0].rok) && (d[l].miesiac + 6 == d2[0].miesiac)
             && (d[0].dzien < d2[0].dzien))
            || ((d[0].rok == d2[0].rok) && (d[l].miesiac + 6 < d2[0].miesiac))
            || ((d[0].rok + 1 == d2[0].rok) && (d[0].miesiac == 7)
                && (d2[0].miesiac == 1) && (d[0].dzien < d2[0].dzien))
            || ((d[0].rok + 1 == d2[0].rok) && (d[0].miesiac == 8)
                && (d2[0].miesiac == 2) && (d[0].dzien < d2[0].dzien))
            || ((d[0].rok + 1 == d2[0].rok) && (d[0].miesiac == 9)
                && (d2[0].miesiac == 3) && (d[0].dzien < d2[0].dzien))
            || ((d[0].rok + 1 == d2[0].rok) && (d[0].miesiac == 10)
                && (d2[0].miesiac == 4) && (d[0].dzien < d2[0].dzien))
            || ((d[0].rok + 1 == d2[0].rok) && (d[0].miesiac == 11)
                && (d2[0].miesiac == 5) && (d[0].dzien < d2[0].dzien))
            || ((d[0].rok + 1 == d2[0].rok) && (d[0].miesiac == 12)
                && (d2[0].miesiac == 6) && (d[0].dzien < d2[0].dzien))
            || ((d[0].rok + 1 == d2[0].rok) && (d[0].miesiac == 7)
                && (d2[0].miesiac > 1))
            || ((d[0].rok + 1 == d2[0].rok) && (d[0].miesiac == 8)
                && (d2[0].miesiac > 2))
            || ((d[0].rok + 1 == d2[0].rok) && (d[0].miesiac == 9)
                && (d2[0].miesiac > 3))
            || ((d[0].rok + 1 == d2[0].rok) && (d[0].miesiac == 10)
                && (d2[0].miesiac > 4))
            || ((d[0].rok + 1 == d2[0].rok) && (d[0].miesiac == 11)
                && (d2[0].miesiac > 5))
            || ((d[0].rok + 1 == d2[0].rok) && (d[0].miesiac == 12)
                && (d2[0].miesiac > 6))
            || (d[0].rok < d2[0].rok)) {
            return true;
            std::cout << "Mozesz sie juz zaszczepic" << std::endl;
        } else {
            return false;
            std::cout << "Nie mozesz sie jeszcze zaszczepic" << std::endl;
        }
    }
}

void zaszczep(Data*& d, Data d2[], unsigned int& l)
{
    Data* new_d = new Data[l + 1];
    std::copy(d, d + l, new_d);
    new_d[l++] = {d2[0].dzien, d2[0].miesiac, d2[0].rok};

    delete[] d;
    d = new_d;
}

void czyWaznyCertyfikat(Data d[], Data d2[], unsigned int l)
{
    if (l > 1) {
        if (((d[l].rok + 1 == d2[0].rok) && (d[l].miesiac == d2[0].miesiac)
             && (d[l].dzien >= d2[0].dzien))
            || ((d[l].rok + 1 == d2[0].rok) && (d[l].miesiac > d2[0].miesiac))
            || (d[l].rok == d2[0].rok)) {
            std::cout << "Twoj certyfikat jest wciaz wazny" << std::endl;
        } else {
            std::cout << "Twoj certyfikat nie jest juz wazny" << std::endl;
        }
    }
}


void rejestruj(Pacjent*& p,
               unsigned int& n,
               const std::string& naz,
               const std::string& log,
               const std::string& has)
{
    bool t;
    for (unsigned int i = 0; i < n; i++) {
        if (p[i].login == log) {
            std::cout << "Istnieje już pacjeny o takim loginie" << std::endl;
            t = false;
            break;
        }
    }

    if (t) {
        Pacjent* new_p = new Pacjent[n + 1];
        std::copy(p, p + n, new_p);
        new_p[n++].login    = log;
        new_p[n++].haslo    = has;
        new_p[n++].nazwisko = naz;
        new_p[n++].l        = 0;
        new_p[n++].daty[0]  = {0, 0, 0};


        delete[] p;
        p = new_p;
    }
}

void zaloguj(Pacjent*& p,
             unsigned int& n,
             const std::string& log,
             const std::string& has)
{
    int a;
    bool t;
    unsigned int i;
    Data daty2[] = {0, 0, 0};
    for (i = 0; i < n; i++) {
        if ((log == p[i].login) && (has == p[i].haslo)) {
            t = true;
            break;
        } else {
            t = false;
        }
    }

    if (t) {
        std::cout << "Login: " << p[i].login << std::endl
                  << "Nazwisko: " << p[i].nazwisko << std::endl
                  << "Data ostatniego szczepienia: " << p[i].daty << std::endl;

        while (a != 5) {
            std::cout << "Co chcesz zrobić?\n 1 - pokaz daty moich szczepien, "
                         "2 - sprawdz czy moge sie zaszczepic"
                         ", 3 - zaszczep, 4 - sprawdz waznosc certyfikatu, 5 - "
                         "wyloguj,"  // 0 - wyjdź"
                      << std::endl;
            std::cin >> a;

            switch (a) {
            case 1:
                wypisz(p[i].daty, p[i].l);
                break;

            case 2:
                std::cout << "Podaj dzisiejsza date: " << std::endl;
                std::cout << "Dzien: ";
                std::cin >> daty2[0].dzien;
                std::cout << std::endl;
                std::cout << "Miesiac: ";
                std::cin >> daty2[0].miesiac;
                std::cout << std::endl;
                std::cout << "Rok: ";
                std::cin >> daty2[0].rok;
                std::cout << std::endl;

                czyMoge(p[i].daty, daty2, p[i].l);

                daty2[0].dzien   = 0;
                daty2[0].miesiac = 0;
                daty2[0].rok     = 0;
                break;

            case 3:
                std::cout << "Podaj dzisiejsza date: " << std::endl;
                std::cout << "Dzien: ";
                std::cin >> daty2[0].dzien;
                std::cout << std::endl;
                std::cout << "Miesiac: ";
                std::cin >> daty2[0].miesiac;
                std::cout << std::endl;
                std::cout << "Rok: ";
                std::cin >> daty2[0].rok;
                std::cout << std::endl;

                if (czyMoge(p[i].daty, daty2, p[i].l)) {
                    zaszczep(p[i].daty, daty2, p[i].l);
                } else {
                    std::cout << "Nie mozesz sie jeszcze zaszczepic"
                              << std::endl;
                }
                daty2[0].dzien   = 0;
                daty2[0].miesiac = 0;
                daty2[0].rok     = 0;
                break;

            case 4:
                std::cout << "Podaj dzisiejsza date: " << std::endl;
                std::cout << "Dzien: ";
                std::cin >> daty2[0].dzien;
                std::cout << std::endl;
                std::cout << "Miesiac: ";
                std::cin >> daty2[0].miesiac;
                std::cout << std::endl;
                std::cout << "Rok: ";
                std::cin >> daty2[0].rok;
                std::cout << std::endl;

                czyWaznyCertyfikat(p[i].daty, daty2, p[i].l);
                daty2[0].dzien   = 0;
                daty2[0].miesiac = 0;
                daty2[0].rok     = 0;

                break;
                /*
                            case 5:
                                wyloguj();
                                break;
                */
            }
        }

    } else {
        std::cout << "Nie instnieje uzytkownik o podanych danych" << std::endl;
    }
}

auto main() -> int
{
    int a;
    std::string lg, hs, naz;
    unsigned int n = 0;
    Pacjent* p     = nullptr;


    while (a != 0) {
        std::cout << "Co chcesz zrobić?\n 1 - zaloguj, 2 - zarejestruj,  0 - "
                     "wyjdź z programu"
                  << std::endl;
        std::cin >> a;

        switch (a) {
        case 1:
            std::cout << "Podaj login: ";
            std::cin >> lg;
            std::cout << std::endl;
            std::cout << "Podaj haslo: ";
            std::cin >> hs;
            std::cout << std::endl;

            zaloguj(p, n, lg, hs);
            std::cout << std::endl;
            break;

        case 2:
            std::cout << "Podaj nazwisko: ";
            std::cin >> naz;
            std::cout << std::endl;
            std::cout << "Podaj login: ";
            std::cin >> lg;
            std::cout << std::endl;
            std::cout << "Podaj haslo: ";
            std::cin >> hs;
            std::cout << std::endl;

            rejestruj(p, n, naz, lg, hs);
            std::cout << std::endl;
            break;
        }
    }

    delete[] p;

    return 0;
}
