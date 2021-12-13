#include <iostream>
#include <string>


// zad 1
/*
auto main() -> int
{
    int p = 2, i;
    bool t;
    std::string l;

    while(p <= 20){
        t = true;
        for(i = 2; i < p; i++)
            if(p % i == 0)
            {
                t = false;
                break;
            }

        if(t)
        {
           for(
        }
        p++;
    }

    std::cout << std::endl;

return 0;
}
*/

// zad2
/*
auto main() -> int
{
    std::string im = "Mikolaj";
    int wg = 72, wz = 177;

    std::cout<<"Imie: "<<im<<std::endl;
    std::cout<<std::endl;
    std::cout<<"Waga: "<<wg<<" kg"<<"\n";\
    std::cout<<std::endl;
    std::cout<<"Wzrost: "<<wz<<" cm"<<"\n";

return 0;
}
*/

// zad3
/*
auto main() -> int
{
    std::string im;
    std::string im2;

        std::cout<<"Prosze wprowadzic pierwsze imie: ";
    std::cin>>im;
    std::cout<<std::endl;

    std::cout<<"Prosze wprowadzic drugie imie: ";
        std::cin>>im2;

    if(im.size()>im2.size()){
        std::cout<<"Pierwsze imie jest dluzsze!"<<std::endl;
    } else if (im.size()<im2.size()){
        std::cout<<"Drugie imie jest dluzsze..."<<std::endl;
    } else{
        std::cout<<"Imiona sa takiej samej dlugosci."<<std::endl;
    }

return 0;
}
*/

// zad4
/*
auto main() -> int
{
        std::string im;
        int m = 0;
    int z = 0;
    for(int i = 0; i < 5; i++)
    {
        std::cout<<"Podaj imie: ";
        std::cin>>im;

        if(im.back()=='a')
        {
            z++;
        }
        else
        {
            m++;
        }
    }

    std::cout<<"ilosc imion zenskich: "<<z<<std::endl;
    std::cout<<"ilosc imion meskich: "<<m<<std::endl;

return 0;
}

*/

// zad5
/*
bool is_even(int n){

    if(n%2==0)
    {
        return true;
    }
    else
    {
        return false;
    }

}

auto main() -> int
{
    int x = 1;
    int y = 6;
    std::cout<<is_even(x)<<std::endl;
    std::cout<<is_even(y)<<std::endl;

return 0;
}
*/

// zad6
/*
bool is_divisible(int l, int d){

    if(l%d==0)
    {
        return true;
    }
    else
    {
        return false;
    }


}

bool is_even(int n){

        if(is_divisible(n,2))
        {
                return true;
        }
        else
        {
                return false;
        }

}

auto main() -> int
{
        int x = 1;
        int y = 6;
        std::cout<<is_even(x)<<std::endl;
        std::cout<<is_even(y)<<std::endl;

return 0;
}

*/

// zad7

auto count_chars(std::string str, char c) -> int
{
    int x = 0;
    for (auto i = 0; i < str.size(); i++) {
        if (str[i] == c) {
            x++;
        }
    }

    return x;
}

auto main() -> int
{
    std::cout << count_chars("Adrianna", 'a') << std::endl;

    return 0;
}
