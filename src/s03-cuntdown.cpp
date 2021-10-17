#include <chrono>
#include <iostream>
#include <string>
#include <thread>

auto main(int argc, char* argv[]) -> int
{
    auto const liczba = std::stoi(argv[1]);

    if (argc > 2) {
        std::cout << "Enter one number!"
                  << "\n";
    } else {
        for (auto i = liczba; i >= 0; i--) {
            std::cout << i << "..."
                      << "\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }

    return 0;
}
