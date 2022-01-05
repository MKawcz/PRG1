#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Data {
    int dzien;
    int miesiac;
    int rok;
    
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
    
};

struct Pacjent {
    std::string login;
    std::string haslo;
    std::string nazwisko;
    std::vector<Data> daty;

};
/*
    void wyloguj()
    {

    }
*/
void wypisz(std::vector<Data> d)
{
    for (size_t i = 0; i < d.size(); i++) {
        std::cout << d[i].dzien << "." << d[i].miesiac << "." << d[i].rok
                  << std::endl;
    }
}

bool czyMoge(std::vector<Data> d, std::vector<Data> d2)
{
    if(d.size() > 0) {
        if (((d.back().rok == d2.back().rok) && (d.back().miesiac + 6 == d2.back().miesiac)
             && (d.back().dzien < d2.back().dzien))
            || ((d.back().rok == d2.back().rok) && (d.back().miesiac + 6 < d2.back().miesiac))
            || ((d.back().rok + 1 == d2.back().rok) && (d.back().miesiac == 7)
                && (d2.back().miesiac == 1) && (d.back().dzien < d2.back().dzien))
            || ((d.back().rok + 1 == d2.back().rok) && (d.back().miesiac == 8)
                && (d2.back().miesiac == 2) && (d.back().dzien < d2.back().dzien))
            || ((d.back().rok + 1 == d2.back().rok) && (d.back().miesiac == 9)
                && (d2.back().miesiac == 3) && (d.back().dzien < d2.back().dzien))
            || ((d.back().rok + 1 == d2.back().rok) && (d.back().miesiac == 10)
                && (d2.back().miesiac == 4) && (d.back().dzien < d2.back().dzien))
            || ((d.back().rok + 1 == d2.back().rok) && (d.back().miesiac == 11)
                && (d2.back().miesiac == 5) && (d.back().dzien < d2.back().dzien))
            || ((d.back().rok + 1 == d2.back().rok) && (d.back().miesiac == 12)
                && (d2.back().miesiac == 6) && (d.back().dzien < d2.back().dzien))
            || ((d.back().rok + 1 == d2.back().rok) && (d.back().miesiac == 7)
                && (d2.back().miesiac > 1))
            || ((d.back().rok + 1 == d2.back().rok) && (d.back().miesiac == 8)
                && (d2.back().miesiac > 2))
            || ((d.back().rok + 1 == d2.back().rok) && (d.back().miesiac == 9)
                && (d2.back().miesiac > 3))
            || ((d.back().rok + 1 == d2.back().rok) && (d.back().miesiac == 10)
                && (d2.back().miesiac > 4))
            || ((d.back().rok + 1 == d2.back().rok) && (d.back().miesiac == 11)
                && (d2.back().miesiac > 5))
            || ((d.back().rok + 1 == d2.back().rok) && (d.back().miesiac == 12)
                && (d2.back().miesiac > 6))
            || (d.back().rok < d2.back().rok)) {
            return true;
            std::cout << "Mozesz sie juz zaszczepic" << std::endl;
        } else {
            return false;
            std::cout << "Nie mozesz sie jeszcze zaszczepic" << std::endl;
        }
    } else if (d.size() == 0) {
        if (((d.back().rok == d2.back().rok) && (d.back().miesiac + 1 == d2.back().miesiac)
             && (d.back().dzien < d2.back().dzien))
            || ((d.back().rok == d2.back().rok) && (d.back().miesiac + 1 < d2.back().miesiac))
            || ((d.back().rok + 1 == d2.back().rok) && (d.back().miesiac == 12)
                && (d2.back().miesiac = 1) && (d.back().dzien < d2.back().dzien))
            || ((d.back().rok + 1 == d2.back().rok) && (d.back().miesiac == 12)
                && (d2.back().miesiac > 1))
            || (d.back().rok < d2.back().rok)) {
            return true;
            std::cout << "Mozesz sie juz zaszczepic" << std::endl;

        } else {
            return false;
            std::cout << "Nie mozesz sie jeszcze zaszczepic" << std::endl;
        }
    } else{
        return true;
        std::cout << "Mozesz sie juz zaszczepic" << std::endl;
	}
}

void zaszczep(std::vector<Data> d, std::vector<Data> d2)
{
    d.push_back({d2.back().dzien, d2.back().miesiac, d2.back().rok});
}

void czyWaznyCertyfikat(std::vector<Data> d, std::vector<Data> d2)
{
    if (d.size() > 0) {
        if (((d.back().rok + 1 == d2.back().rok) && (d.back().miesiac == d2.back().miesiac)
             && (d.back().dzien >= d2.back().dzien))
            || ((d.back().rok + 1 == d2.back().rok) && (d.back().miesiac > d2.back().miesiac))
            || (d.back().rok == d2.back().rok)) {
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
               const std::string& has,
			   std::vector<Data>& d)
{
    bool t;
    for (unsigned int i = 0; i < n; i++) {
        if (p[i].login == log) {
            std::cout << "Istnieje ju¿ pacjeny o takim loginie" << std::endl;
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
		new_p[n++].daty = d;

        delete[] p;
        p = new_p;
    }
}

void zaloguj(Pacjent*& p,
             unsigned int& n,
             const std::string& log,
             const std::string& has)
{
    int a, x, y, z;
    bool t;
    unsigned int i;
    std::vector<Data> daty2;
    
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
                  << "Data ostatniego szczepienia: " << p[i].daty.back().dzien <<"."<< p[i].daty.back().miesiac <<"."<< p[i].daty.back().rok << std::endl;

        while (a != 5) {
            std::cout << "Co chcesz zrobiæ?\n 1 - pokaz daty moich szczepien, "
                         "2 - sprawdz czy moge sie zaszczepic"
                         ", 3 - zaszczep, 4 - sprawdz waznosc certyfikatu, 5 - "
                         "wyloguj,"  // 0 - wyjdŸ"
                      << std::endl;
            std::cin >> a;

            switch (a) {
            case 1:
                wypisz(p[i].daty);
                break;

            case 2:
                std::cout << "Podaj dzisiejsza date: " << std::endl;
                std::cout << "Dzien: ";
                std::cin >> x;
                std::cout << std::endl;
                std::cout << "Miesiac: ";
                std::cin >> y;
                std::cout << std::endl;
                std::cout << "Rok: ";
                std::cin >> z;
                std::cout << std::endl;

				daty2.push_back({x,y,z});
                czyMoge(p[i].daty, daty2);

                daty2.clear();
                break;

            case 3:
                std::cout << "Podaj dzisiejsza date: " << std::endl;
                std::cout << "Dzien: ";
                std::cin >> x;
                std::cout << std::endl;
                std::cout << "Miesiac: ";
                std::cin >> y;
                std::cout << std::endl;
                std::cout << "Rok: ";
                std::cin >> z;
                std::cout << std::endl;

				daty2.push_back({x,y,z});
                if (czyMoge(p[i].daty, daty2)) {
                    zaszczep(p[i].daty, daty2);
                } else {
                    std::cout << "Nie mozesz sie jeszcze zaszczepic"
                              << std::endl;
                }
                
                daty2.clear();
                break;

            case 4:
                std::cout << "Podaj dzisiejsza date: " << std::endl;
                std::cout << "Dzien: ";
                std::cin >> x;
                std::cout << std::endl;
                std::cout << "Miesiac: ";
                std::cin >> y;
                std::cout << std::endl;
                std::cout << "Rok: ";
                std::cin >> z;
                std::cout << std::endl;

				daty2.push_back({x,y,z});
                czyWaznyCertyfikat(p[i].daty, daty2);
                
				daty2.clear();
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

int main()
{
    int a;
    std::string lg, hs, naz;
    unsigned int n = 0;
    Pacjent* p     = nullptr;


    while (a != 0) {
        std::cout << "Co chcesz zrobiæ?\n 1 - zaloguj, 2 - zarejestruj,  0 - "
                     "wyjdŸ z programu"
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

            rejestruj(p, n, naz, lg, hs, {0,0,0});
            std::cout << std::endl;
            break;
        }
    }

    delete[] p;

    return 0;
}
