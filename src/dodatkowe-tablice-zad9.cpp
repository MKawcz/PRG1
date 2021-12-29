#include <iostream>

auto main() -> int
{
    int n[9] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
    int k, l, i = 0;

    std::cout << "Podaj kwote w zl: ";
    std::cin >> k;

    while (k > 0)  // dopoki nie wydano calej reszty
    {
        if (k >= n[i])  // sprawdz czy mozna wydac danym nominalem
        {
            l = k / n[i];        // ile razy wydac dany nominal
            k = k - (n[i] * l);  // zmniejsz reszte o wydany nominal
            std::cout << n[i] << " zl  -  " << l << " szt"
                      << std::endl;  // wypisz wynik
        }
        i++;  // rozpatrz kolejny nominal
    }

    return 0;
}
