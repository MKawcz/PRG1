#include <iostream>
#include <string>

auto main(int argc, char* argv[]) -> int
{
    auto znak  = std::string{argv[1]};
    auto znak2 = std::string{argv[2]};

    if (((znak == "-r") && (znak2 == "-l"))
        || ((znak == "-l") && (znak2 == "-r"))) {
        for (auto m = argc - 1; m >= 3; m--) {
            std::cout << argv[m] << "\n";
        }
    } else if (((znak == "-r") && (znak2 == "-n"))
               || ((znak == "-n") && (znak2 == "-r"))) {
        for (auto n = argc - 1; n >= 3; n--) {
            std::cout << argv[n] << " ";
        }
    } else if (znak == "-r") {
        for (auto i = argc - 1; i >= 2; i--)  // argc-1, poniewaz argc dziala
                                              // jak rozmiar tablicy argv,
                                              // argv[argc] da null character
        {
            std::cout << argv[i] << " ";
        }
        std::cout << "\n";
    } else if (znak == "-n") {
        for (auto k = 2; k <= argc - 1; k++) {
            std::cout << argv[k] << " ";
        }
    } else if (znak == "-l") {
        for (auto l = 2; l <= argc - 1; l++) {
            std::cout << argv[l] << "\n";
        }
    } else {
        for (auto j = 1; j <= argc - 1; j++) {
            std::cout << argv[j] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
