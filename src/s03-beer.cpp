#include <iostream>
#include <string>


auto main(int argc, char* argv[]) -> int
{
    auto liczba = (argc > 1)
                      ? std::stoi(argv[1])
                      : 99;  // większe od 1, poniewaz program uruchomiony bez
                             // podanego argumentu, bedzie posiadal jeden
                             // domyslny, ktorym jest sciezka

    if (argc > 2) {
        std::cout << "Enter one number!"
                  << "\n";
    } else {
        for (auto i = liczba; i >= 0; i--) {
            if (i == 0) {
                std::cout << "No more bottles of beer on the wall, no more "
                             "bottles of beer."
                          << "\n"
                          << "Go to the store and buy some more, 99 bottles of "
                             "beer on the wall..."
                          << "\n";
            } else if (i == 2) {
                std::cout << i << " bottles of beer on the wall, " << i
                          << " bottles of beer."
                          << "\n"
                          << "Take one down, pass it around, " << i - 1
                          << " bottle of beer on the wall..."
                          << "\n";
            } else if (i == 1) {
                std::cout << i << " bottle of beer on the wall, " << i
                          << " bottle of beer."
                          << "\n"
                          << "Take one down, pass it around, no more bottles "
                             "of beer on the wall..."
                          << "\n";
            } else {
                std::cout << i << " bottles of beer on the wall, " << i
                          << " bottles of beer."
                          << "\n"
                          << "Take one down, pass it around, " << i - 1
                          << " bottles of beer on the wall..."
                          << "\n";
            }
        }
    }

    return 0;
}
