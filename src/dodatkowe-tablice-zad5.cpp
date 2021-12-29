#include <algorithm>
#include <iostream>
#include <string>

void dodaj(std::string*& s, unsigned int& n, const std::string& str)
{
    if (std::find(s, s + n, str) != (s + n)) {
        std::cout << "Istnieje juz takie slowo" << std::endl;
        return;
    }

    std::string* new_s = new std::string[n + 1];  // tworzę nową tablicę o 1
                                                  // większą
    std::copy(s, s + n, new_s);  // kopiuje zawartość starej do nowej
    new_s[n++] = str;

    delete[] s;  // usuwam starą tablicę
    s = new_s;
}

void wypisz(std::string s[], unsigned int n)
{
    for (unsigned int i = 0; i < n; i++) {
        std::cout << s[i] << std::endl;
    }
}

void usun(std::string*& s, unsigned int& n, const std::string& str)
{
    bool t;
    unsigned int i;
    for (i = 0; i < n; i++) {
        if (str == s[i]) {
            t = true;
            break;
        } else {
            t = false;
        }
    }

    if (t == true) {
        for (unsigned int j = i; j < n - 1; j++) {
            s[j] = s[j + 1];
        }

        std::string* new_s = new std::string[n - 1];
        n--;
        std::copy(s, s + n, new_s);

        delete[] s;
        s = new_s;

    } else if (t == false) {
        std::cout << "Podanego slowa nie ma w slowniku" << std::endl;
    }
}

void wyszukaj(std::string s[], unsigned int n, const std::string& str)
{
    bool t;
    unsigned int i;
    for (i = 0; i < n; i++) {
        if (str == s[i]) {
            t = true;
            break;
        } else {
            t = false;
        }
    }

    if (t == true) {
        std::cout << s[i] << std::endl;
    } else if (t == false) {
        std::cout << "Podanego slowa nie ma w slowniku" << std::endl;
    }
}

void sortuj(std::string s[], unsigned int n)
{
    std::sort(s, s + n);

    for (unsigned int i = 0; i < n; i++) {
        std::cout << s[i] << std::endl;
    }
}


auto main() -> int
{
    unsigned int n       = 0;
    std::string* slownik = nullptr;
    int a;
    std::string sl;

    while (a != 0) {
        std::cout << "Co chcesz zrobić?\n 1 - dodaj slowo, 2 - usun slowo,"
                     " 3 - wyszukaj slowo, 4 - wypisz slownik, 5 - "
                     "sortuj slownik, 0 - wyjdź\n";
        std::cin >> a;

        switch (a) {
        case 1:
            std::cout << "Podaj slowo do dodania: ";
            std::cin >> sl;
            dodaj(slownik, n, sl);
            std::cout << std::endl;

            break;

        case 2:
            std::cout << "Podaj slowo do usuniecia: ";
            std::cin >> sl;
            usun(slownik, n, sl);
            std::cout << std::endl;

            break;

        case 3:
            std::cout << "Podaj slowo do wyszukania: ";
            std::cin >> sl;

            wyszukaj(slownik, n, sl);
            std::cout << std::endl;

            break;

        case 4:
            wypisz(slownik, n);
            std::cout << std::endl;

            break;

        case 5:
            sortuj(slownik, n);
            std::cout << std::endl;

            break;
        }
    }


    delete[] slownik;
    return 0;
}
