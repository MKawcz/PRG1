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
                std::cout << j << "\t";
            }
            k++;
            std::cout << std::endl;
        }
    } else if (w == 'b') {
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < n - i; j++) {
                std::cout << 0 << "\t ";
            }

            for (int l = 1; l <= i; l++) {
                std::cout << l << "\t ";
            }
            std::cout << std::endl;
        }

    } else if (w == 'd') {
        for (int i = n; i >= 1; i--) {
            for (int j = i; j >= 1; j--) {
                std::cout << j << "\t";
            }

            for (int l = 0; l < n - i; l++) {
                std::cout << 0 << "\t";
            }
            std::cout << std::endl;
        }
    } else if (w == 'c') {
        for (int i = 0; i < n; i++) {
            for (int j = 2; j <= n * 2; j += 2) {
                std::cout << (j <= 2 * i ? 2 * (i + 1) : j) << "\t";
            }
            std::cout << std::endl;
        }
    }

    return 0;
}
