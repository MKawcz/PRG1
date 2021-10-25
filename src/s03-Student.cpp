#include <s25441/Student.h>

#include <iomanip>
#include <iostream>
#include <string>
Student::Student(const std::string im,
                 const std::string naz,
                 const std::string id,
                 short int sem,
                 float sr)
        : imie{im}, nazwisko{naz}, indeks{id}, semestr{sem}, srednia_ocen{sr}
{}

auto ::Student::to_string() const -> std::string
{
    return imie + " " + nazwisko + " " + indeks + " " + std::to_string(semestr)
           + " " + std::to_string(srednia_ocen);
}

auto main() -> int
{
    auto ja = Student("Mikolaj", "Kawczynski", "s25441", 1, 0);
    std::cout << ja.to_string() << std::endl;


    return 0;
}
