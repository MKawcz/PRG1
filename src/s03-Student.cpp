#include <s25441/Student.h>

#include <iomanip>
#include <iostream>
#include <string>
Student::Student(const std::string& imie_,
                 const std::string& nazwisko_,
                 const std::string& indeks_,
                 short int semestr_,
                 float srednia_ocen_)
        : imie{imie_}
        , nazwisko{nazwisko_}
        , indeks{indeks_}
        , semestr{semestr_}
        , srednia_ocen{srednia_ocen_}
{}

auto ::Student::to_string() const -> std::string
{
    return imie + " " + nazwisko + " " + indeks + " " + std::to_string(semestr)
           + " " + std::to_string(srednia_ocen);
}

auto main() -> int
{
    auto ja = Student{"Mikolaj", "Kawczynski", "s25441", 1, 0};
    std::cout << ja.to_string() << std::endl;


    return 0;
}
