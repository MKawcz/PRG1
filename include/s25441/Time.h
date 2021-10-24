#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <string>


struct Time {
    int godzina;
    int minuta;
    int sekunda;

    auto to_string() const -> std::string;
    auto next_hour()  -> void;
    auto next_minute()  -> void;
    auto next_second()  -> void;

    Time ();
};


