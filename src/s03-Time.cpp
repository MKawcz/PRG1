#include <s25441/Time.h>

#include <chrono>
#include <iomanip>
#include <iostream>
#include <string>
#include <thread>

Time::Time(int godz, int min, int sek)
        : godzina{godz}, minuta{min}, sekunda{sek}
{}

auto ::Time::next_hour() -> void
{
    if (godzina < 23) {
        godzina++;
    } else {
        godzina = 0;
    }
}

auto ::Time::next_minute() -> void
{
    if (minuta < 59) {
        minuta++;
    } else {
        next_hour();
        minuta = 0;
    }
}

auto ::Time::next_second() -> void
{
    if (sekunda < 59) {
        sekunda++;
    } else {
        next_minute();
        sekunda = 0;
    }
}


auto ::Time::to_string() const -> std::string
{
    std::string godz = std::to_string(godzina);
    std::string min  = std::to_string(minuta);
    std::string sek  = std::to_string(sekunda);

    if (godzina < 10) {
        godz = "0" + godz;
    }

    if (minuta < 10) {
        min = "0" + min;
    }

    if (sekunda < 10) {
        sek = "0" + sek;
    }


    return godz + ":" + min + ":" + sek;
}

auto ::Time::time_of_day() const -> Time_of_day
{
    if ((godzina >= 23) && (godzina <= 5)) {
        return Noc;
    } else if ((godzina >= 6) && (godzina <= 10)) {
        return Rano;
    } else if ((godzina >= 11) && (godzina <= 16)) {
        return Dzien;
    } else if ((godzina >= 17) && (godzina <= 22)) {
        return Wieczor;
    }
}

enum class Time_of_day {
    Rano,
    Dzien,
    Wieczor,
    Noc

};

auto to_string(Time_of_day t) -> std::string
{
    if (Time_of_day == Rano) {
        cout << "Rano";
    }
}

auto main() -> int
{
    auto czas = Time(23, 59, 59);
    std::cout << czas.to_string() << std::endl;
    czas.next_minute();
    std::cout << czas.to_string() << std::endl;
    czas.next_second();
    std::cout << czas.to_string() << std::endl;
    czas.next_hour();
    std::cout << czas.to_string() << std::endl;
    return 0;
}
