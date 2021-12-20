#include <iostream>
#include <string>
#include <vector>
// zad 1
/*
auto average_of(std::vector<int> vec) -> float
{
    int x = 0;
    for(size_t i = 0; i < vec.size(); i++)
    {
        x = x + vec[i];
    }

    return float(x)/float(vec.size());
}

auto main() -> int
{
    auto liczby = std::vector<int>{5, 2, 5, 3};
    std::cout<<average_of(liczby)<<std::endl;


return 0;
}
*/

// zad 2

auto filter_palindromes(std::vector<std::string> vec)
    -> std::vector<std::string>
{
    for (size_t i = 0; i < vec.size(); i++) {
        for (size_t i = 0; i < vec[i].size() / 2; i++) {
            while (vec[i] == str[str.size() - i - 1]) {
                return true;
            }
        }
        return false;
    }

    return;
}

auto main() -> int
{
    auto liczby = std::vector<int>{5, 2, 5, 3};
    std::cout << average_of(liczby) << std::endl;


    return 0;
}
