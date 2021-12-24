#include <algorithm>
#include <iostream>
#include <sstream>
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

auto filter_palindromes(std::vector<std::string> vec)-> std::vector<std::string>
{
    std::vector<std::string> a;
    for (size_t i = 0; i < vec.size(); i++) {
    if(is_palindrome(vec[i]))
    {
        a.push_back(vec[i]);
    }
    }

    return a;
}

auto main() -> int
{
    auto slowa = std::vector<std::string>{"anna", "maciek", "ada", "miki"};
    auto przefiltrowane = filter_palindromes(slowa);

    for(size_t i = 0; i < przefiltrowane.size(); i++)
    {
    std::cout<<przefiltrowane[i]<<" ";
    }

    std::cout<<std::endl;

    return 0;
}
*/


// zad 3
/*
auto dot_product(std::vector<int> vec, std::vector<int> vec2) -> int
{
    int x=0;
    if(vec.size() !=  vec2.size())
    {
    return 0;
    }
    else
    {
        for(size_t i = 0; i < vec.size(); i++)
        {
        x += vec[i]*vec2[i];
        }
    }

    return x;
}

auto main() -> int
{
    auto liczby = std::vector<int>{5, 2, 5, 3};
    auto liczby2 = std::vector<int>{4, 3, 2, 1};
    std::cout<<dot_product(liczby, liczby2)<<std::endl;


return 0;
}
*/

// zad4 i 6
/*
struct Student
{
    std::string imie;
    std::string nazwisko;
    std::vector<int> oceny;

    Student(std::string im, std::string naz, std::vector<int> o)
        {
        imie = im;
        nazwisko = naz;
        oceny = o;
        }

};

auto average_of(Student a) -> float
{
        int x = 0;
        for(size_t i = 0; i < a.oceny.size(); i++)
        {
             x = x + a.oceny[i];
        }

        return float(x)/float(a.oceny.size());
}

auto get_best_student(std::vector<Student> st) -> Student
{
    auto brak = Student("brak", "studentow", {});

        if(st.empty()) return brak;

    auto tmp = average_of(st[0]);
    auto best = st[0];
    for(size_t i = 0; i < st.size(); i++)
    {
        if(average_of(st[i]) > tmp)
        {
             tmp = average_of(st[i]);
             best = st[i];
        }
    }
    return best;
}
*/

/*
auto main() -> int
{
    auto Maciek = Student("Maciek", "Nowak", {2,1,1,1});
    //std::cout<<average_of(Maciek)<<std::endl;
    auto Mikolaj = Student("Mikolaj", "Kowalski", {2,1,5,5});
    auto Jurek = Student("Jurek", "Kowalski", {2,4,5,3,2,1});
    auto Tomek = Student("Tomek", "Kozak", {6,5,6});

    auto vec = std::vector<Student>{Maciek, Jurek, Tomek, Mikolaj};

    auto naj = get_best_student(vec);

        std::cout<<naj.imie<<" "<<naj.nazwisko<<" "<<average_of(naj)<<std::endl;


return 0;
}
*/


// zad 5
/*
auto split(std::string str) -> std::vector<std::string>
{
        std::vector<std::string> a;
        std::string b;
        for( size_t i = 0; i < str.size(); i++ )
        {
                if(str[i] != ' ')
                {
                        b += str[i];
                }

                else if( str[i] == ' ' )
                {
                        a.push_back(b);
                        b.clear();
                }
        }
        a .push_back( b );
        return a;
}


int main()
{
    std::string s = "ala ma kota";
    std::vector<std::string> przefiltrowane = split(s);

    for(size_t i = 0; i < przefiltrowane.size(); i++)
    {
        std::cout<<przefiltrowane[ i ] <<" ";
    }
    std::cout<<std::endl;
    return 0;
}
*/

// zad 7 i 8
/*
struct Group
{
        std::string nazwa;
        std::vector<Student> studenci;

        Group(std::string naz, std::vector<Student> s)
        {
                nazwa = naz;
                studenci = s;
        }


};

void add_to_group(Group& g, Student const& st)
{
    g.studenci.push_back(st);
}

auto best_groups_name(const std::vector<Group> &gr) -> Group
{
    auto brak = Group("brak grupy lub studentow", {});

    if(gr.empty() || gr[0].studenci.empty()) return brak;

        auto tmp = average_of(gr[0].studenci[0]);
        auto best = gr[0];
    std::vector<float> sr;
    for(size_t i = 0; i < gr.size(); i++)
    {
        std::vector<float> sr;

        for(auto &s : gr[i].studenci)
        {

            sr.push_back(average_of(s));
        }

        std::sort(sr.begin(), sr.end());

        if(gr[i].studenci.size() % 2 == 0)
        {
            if((sr[sr.size()/2 - 1] + sr[sr.size()/2]) / 2 > tmp)
            {
                tmp = (sr[sr.size()/2] + sr[sr.size()/2]) / 2;
                best = gr[i];
            }
        }
        else
        {
            if(sr[(sr.size() - 1) / 2] > tmp)
            {
                tmp = sr[(sr.size() - 1) / 2];
                best = gr[i];
            }
        }

    }

    return best;
}

auto main() -> int
{
    auto Stasiek = Student("Stasiek", "Kowalski", {3,4,5,5});
    auto Grzesiek = Student("Grzesiek", "Nowak", {6,6,4,5});
    auto c = Group("c", {});

    add_to_group(c, Stasiek);
    add_to_group(c, Grzesiek);

    auto Mikolaj = Student("Mikolaj", "Kowalski", {2,1,5,5});
        auto Kuba = Student("Kuba", "Nowak", {6,6,4,5,4,4});
    auto Piotr = Student("Piotr", "Nowak", {2,2,1,5,4,4});
    auto b = Group("b", {});

        add_to_group(b, Mikolaj);
        add_to_group(b, Kuba);
    add_to_group(b, Piotr);


    auto Mariusz = Student("Mariusz", "Krawczyk", {6});
        auto d = Group("d", {});

        add_to_group(d, Mariusz);


    std::cout<<c.nazwa<<": "<<std::endl;

    for(size_t i = 0; i < c.studenci.size(); i++)
    {
        std::cout<<c.studenci[i].imie<<std::endl;
    }


    auto vec = std::vector<Group>{c,b,d};
    auto najgrupa = best_groups_name(vec);
    std::cout<<najgrupa.nazwa<<std::endl;

return 0;
}
*/

// zad 9
/*
bool contains_all(std::vector<int> vec, std::vector<int> vec2)
{
//Sortowanie wektorów
        std::sort(vec.begin(), vec.end());
        std::sort(vec2.begin(), vec2.end());

        auto v_pos {vec.begin()};

//Czy każdy element vectora 2...
        for (auto& elem : vec2)
        {
            //Zawiera się w wektorze pierwszym
            while (v_pos < vec.end())
            {
                if (elem == *v_pos)
                {
                    // Tak, więc przechodzę do następnego elementu vec
                    ++v_pos;
                    // Sprawdzam kolejny element vec2
                    break;
                }
                else if (*v_pos > elem)
                {
                    // Dalej już nie znajdziemy bo wektory są posortowane
                    return false;
                }
                v_pos++;
            }
        }

        return ((v_pos < vec .end())); // TRUE gdy Nie przekroczyło zakresu vec
i sprawdzono wszystkie elementy vec2.

}

auto main() -> int
{
    auto vec = std::vector<int>{2,3,5,2,1,4,5,6,7,8};
    auto vec2 = std::vector<int>{2,3,5,2};

    std::cout<<contains_all(vec, vec2)<<std::endl;

return 0;
}
*/

// zad 10

auto main() -> int
{
    std::string input;

    std::cout << "Podaj dwie litery: " << std::endl;

    while (std::getline(std::cin, input) && input != "stop") {
        std::vector<std::string> elements;
        std::string item;
        std::stringstream ss(input);

        while (std::getline(ss, item, ' ')) {
            elements.push_back(item);
        }
        std::sort(elements.begin(), elements.end());
        if (elements.size() > 1) {
            char start = elements[0][0];
            char stop  = elements[1][0];
            while (start <= stop) {
                std::cout << start;
                start++;
            }
        } else if (elements.size() == 1) {
            std::cout << elements[0];
        }
        std::cout << "\n";
    }

    return 0;
}
