
#include <iostream>
#include <string>

void pola(char tab[])  // funkcja rysujaca plansze
{
    for (auto i = 1; i <= 9; i++) {
        std::cout << " " << tab[i] << " ";
        if (i % 3) {
            std::cout << "|";
        } else if (i != 9) {
            std::cout << "\n"
                      << "---+---+---"
                      << "\n";
        } else {
            std::cout << std::endl;
        }
    }
}

void wybor(char tab[], char& gracz)  // gracz wybiera pole do wstawienia znaku
{
    pola(tab);
    int a;

    std::cout << "Gracz " << gracz << " gdzie wstawic znak? "
              << "\n";

    std::cout << "wybierz pole: ";
    std::cin >> a;
    std::cout << std::endl;

    if ((tab[a] == 'O') || (tab[a] == 'X')) {
        std::cout << "Podane pole jest już zajete!" << std::endl;
    } else if ((a < 1) || (a > 9)) {
        std::cout << "Podane pole wychodzi poza plansze!" << std::endl;
    } else if ((a >= 1) && (a <= 9) && (tab[a] == ' ')) {
        tab[a] = gracz;
        gracz  = (gracz == 'O') ? 'X' : 'O';
    }
}

bool wygrana(char t[], char g)
{
    bool test;
    int i;

    test = false;
    for (i = 1; i <= 7; i += 3) {
        test |= ((t[i] == g) && (t[i + 1] == g) && (t[i + 2] == g));
    }

    for (i = 1; i <= 3; i++) {
        test |= ((t[i] == g) && (t[i + 3] == g) && (t[i + 6] == g));
    }
    test |= ((t[1] == g) && (t[5] == g) && (t[9] == g));
    test |= ((t[3] == g) && (t[5] == g) && (t[7] == g));

    if (test) {
        pola(t);
        std::cout << "\n Gracz " << g << " zwycieza!\n";
        return true;
    }
    return false;
}

bool remis(char tab[])
{
    for (int i = 1; i <= 9; i++) {
        if (tab[i] == ' ')
            return false;
    }

    pola(tab);
    std::cout << "\n remis! \n";
    return true;
}


auto main() -> int
{
    char tab[10], g, w;

    do {
        for (int i = 1; i <= 9; i++) {
            tab[i] = ' ';
        }
        g = 'O';
        while (!wygrana(tab, 'X') && !wygrana(tab, 'O') && !remis(tab)) {
            wybor(tab, g);
        }
        std::cout << "Jeszcze raz ? (T = TAK) : ";
        std::cin >> w;
        std::cout << "\n\n\n";
    } while ((w == 'T') || (w == 't'));


    return 0;
}
