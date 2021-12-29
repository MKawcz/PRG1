#include <iostream>

auto main() -> int
{
    char w;
    int n, k;

    std::cout << "Podaj wariant macierzy (a,b,c,d):" << std::endl;
    std::cin >> w;

    std::cout << "Podaj rozmiar macierzy:" << std::endl;
    std::cin >> n;

    k = n;

    if (w == 'a') {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= k; j++) {
                std::cout << j << " ";
            }
            k++;
            std::cout << std::endl;
        }
    } else if (w == 'b') {
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < n - i; j++) {
                std::cout << 0 << " ";
            }

            for (int l = 1; l <= i; l++) {
                std::cout << l << " ";
            }
            std::cout << std::endl;
        }

    } else if (w == 'd') {
        for (int i = n; i >= 1; i--) {
            for (int j = i; j >= 1; j--) {
                std::cout << j << " ";
            }

            for (int l = 0; l < n - i; l++) {
                std::cout << 0 << " ";
            }
            std::cout << std::endl;
        }
    }
    return 0;
}
