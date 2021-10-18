#include <iostream>
#include <string>

auto main() -> int
{
    int a;
    int b;
    int c;
    int d;


    std::cout << "Wybierz figure: 1[trojkat], 2[prostokat], 3[trapez]: "
              << "\n";
    std::cin >> c;

    if (c == 1) {
        std::cout << "a = ";
        std::cin >> a;
        std::cout << "h = ";
        std::cin >> b;
        std::cout << "Pole trojkata: " << a * b / 2 << "\n";
    } else if (c == 2) {
        std::cout << "a = ";
        std::cin >> a;
        std::cout << "b = ";
        std::cin >> b;
        std::cout << "Pole prostokata: " << a * b << "\n";
    } else if (c == 3) {
        std::cout << "a = ";
        std::cin >> a;
        std::cout << "b = ";
        std::cin >> b;
        std::cout << "h = ";
        std::cin >> d;
        std::cout << "Pole trapezu: " << (a + b) * d / 2 << "\n";
    }


    return 0;
}
