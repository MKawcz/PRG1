#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>


struct Student {
    std::string const imie;
    std::string const nazwisko;
    std::string const indeks;
    short int semestr;
    float srednia_ocen;

    auto to_string() const -> std::string;
    Student(const std::string imie,
            const std::string nazwisko,
            const std::string indeks,
            short int semestr,
            float srednia_ocen);
};

#endif
