#include <iostream>
#include <string>

// zad 1

auto main() -> int
{
    int p = 2, i;
    bool t;
    std::string str;

    while (p <= 20) {
        t = true;
        for (i = 2; i < p; i++)
            if (p % i == 0) {
                t = false;
                break;
            }

        if (t) {
            str += std::to_string(p) + " ";
        }
        p++;
    }

    std::cout << str << std::endl;
    std::cout << str << std::endl;

    return 0;
}


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
/*
int count_chars(std::string str, char c)
{
    int x = 0;
    for (std::size_t i = 0; i < str.size(); i++) {
        if (str[i] == c) {
            x++;
        }
    }

    return x;
}

int main()
{
    std::cout << count_chars("adrianna", 'a') << std::endl;

    return 0;
}
*/


// zad8
/*
void show_chars(std::string str, int a)
{
    for (std::size_t i = 0; i <= str.length(); i++) {
        if ((i > 0) && (i % a == 0)) {
            std::cout<<str[i-1]<<" ";
        }
    }
}

auto main() -> int
{
    show_chars("konstantynopolitanczykowianeczka", 3);

    std::cout<<std::endl;

    return 0;
}
*/

// zad 9
/*
bool is_palindrome(std::string str)
{

    for (std::size_t i = 0; i < str.size() / 2; i++) {
        while (str[i] == str[str.size() - i - 1]) {
            return true;
        }
    }
   return false;
}

auto main() -> int
{

   std::cout<<is_palindrome("anna")<<std::endl;

return 0;
}
*/

// zad 10
/*
void box_print(std::string a, std::string b, std::string c, std::string d,
std::string e)
{
    std::string tab[5] = { a, b, c, d, e };

    size_t max_size = 0;
    size_t current_size = 0;

    for(auto s : tab)
    {
        if (s.size() > max_size)
            max_size = s.size();
    }


    for(size_t j = 0; j < max_size + 4; j++)
    {
        std::cout<<"*";
    }

    std::cout << std::endl;

    for(auto i = 0; i < 5; i++)
    {
    std::cout<<"* "<<tab[i];
    current_size = tab[i].size();

    for(size_t l = 0; l < max_size - current_size; l++)
    {
        std::cout<<" ";
    }

    std::cout<<" *"<<std::endl;
    }

    for(size_t k = 0; k < max_size + 4; k++)
    {
        std::cout<<"*";
    }

    std::cout << std::endl;

}

auto main() -> int
{
    box_print("Hello", "World", "in", "a", "frame");

    box_print("Siemka", "tu", "Mikolaj", "co", "tam");

    box_print("Poniedzialek", "wieczor", "i", "humor", "kaput");


    return 0;
}
*/
