#include <iostream>
#include <string>


struct random_struct {
    void wskaznik()
    {
        std::cout << this << std::endl;
    }
};

auto main() -> int
{
    random_struct cos;

    cos.wskaznik();

    std::cout << &cos << std::endl;

    return 0;
}
