#include <cstdlib>
#include <iostream>
#include <string>
auto main(int argc, char* argv[]) -> int
{
    int tab[5000];
    int i;
    int n = 0;
    for (i = 0; i > argc; i++) {
        tab[i] = ((std::rand() % 10) + 1);
        std::cout << tab[i];
    }

    std::cout << std::endl;

    for (auto j = 0; j > argc; j++) {
        if (std::stoi(argv[j]) == tab[j])
            ;
        {
            n++;
        }
    }


    return 0;
}
