#include <s25441/Time.h>

#include <iomanip>
#include <iostream>
#include <string>

Time::Time(int godz, int min, int sek)
        : godzina{godz}, minuta{min}, sekunda{sek}
{
    if (sekunda > 59) {
        sekunda = sekunda - 60;
        minuta++;
    } else if (sekunda < 0) {
        sekunda = 60 + sekunda;
        minuta--;
    }

    if (minuta > 59) {
        minuta = minuta - 60;
        godzina++;
    } else if (minuta < 0) {
        minuta = 60 + minuta;
        godzina--;
    }


    if (godzina > 23) {
        godzina = godzina - 24;
    } else if (godzina < 0) {
        godzina = 24 + godzina;
    }
}

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
    if ((godzina == 23) || ((godzina >= 0) && (godzina <= 5))) {
        return Time_of_day::Noc;
    } else if ((godzina >= 6) && (godzina <= 10)) {
        return Time_of_day::Rano;
    } else if ((godzina >= 11) && (godzina <= 16)) {
        return Time_of_day::Dzien;
    } else if ((godzina >= 17) && (godzina <= 22)) {
        return Time_of_day::Wieczor;
    } else {
        return Time_of_day::Niezdefiniowany;
    }
}

auto ::Time::to_string(Time_of_day t) -> std::string
{
    if (t == Time_of_day::Rano) {
        return "Rano";
    } else if (t == Time_of_day::Dzien) {
        return "Dzien";
    } else if (t == Time_of_day::Wieczor) {
        return "Wieczor";
    } else if (t == Time_of_day::Noc) {
        return "Noc";
    } else {
        return "Niezdefiniowany";
    }
}


auto ::Time ::operator+(Time const& o) const -> Time
{
    return Time(godzina + o.godzina, minuta + o.minuta, sekunda + o.sekunda);
}

auto ::Time ::operator-(Time const& o) const -> Time
{
    return Time(godzina - o.godzina, minuta - o.minuta, sekunda - o.sekunda);
}

auto ::Time ::operator>(Time const& o) const -> bool
{
    auto godziny  = godzina * 3600;
    auto minuty   = minuta * 60;
    auto ile_s    = sekunda + godziny + minuty;
    auto ogodziny = o.godzina * 3600;
    auto ominuty  = o.minuta * 60;
    auto oile_s   = o.sekunda + ogodziny + ominuty;


    return (ile_s > oile_s);
}

auto ::Time ::operator<(Time const& o) const -> bool
{
    auto godziny  = godzina * 3600;
    auto minuty   = minuta * 60;
    auto ile_s    = sekunda + godziny + minuty;
    auto ogodziny = o.godzina * 3600;
    auto ominuty  = o.minuta * 60;
    auto oile_s   = o.sekunda + ogodziny + ominuty;


    return (ile_s < oile_s);
}

auto ::Time ::operator==(Time const& o) const -> bool
{
    return (godzina == o.godzina && minuta == o.minuta && sekunda == o.sekunda);
}

auto ::Time ::operator!=(Time const& o) const -> bool
{
    return (godzina != o.godzina || minuta != o.minuta || sekunda != o.sekunda);
}


auto ::Time ::count_seconds() const -> uint64_t
{
    auto godziny = godzina * 3600;
    auto minuty  = minuta * 60;
    auto ile_s   = sekunda + godziny + minuty;
    return ile_s;
}


auto ::Time ::count_minutes() const -> uint64_t
{
    auto godziny = godzina * 60;
    auto ile_m   = godziny + minuta;
    return ile_m;
}


auto ::Time ::time_to_midnight() const -> Time
{
    return Time(23 - godzina, 59 - minuta, 60 - sekunda);
}


auto main() -> int
{
    auto czas  = Time(23, 59, 59);
    auto czas2 = Time(10, 46, 1);

    std::cout << "pierwszy obiekt czasu: " << czas.to_string() << std::endl;
    std::cout << "czas do polnocy: " << czas.time_to_midnight().to_string()
              << std::endl;
    std::cout << "pora dnia: " << czas.to_string(czas.time_of_day())
              << std::endl;
    std::cout << "liczba sekund: " << czas.count_seconds() << std::endl;
    std::cout << "liczba minut: " << czas.count_minutes() << std::endl;
    czas.next_minute();

    std::cout << "kolejna minuta: " << czas.to_string() << std::endl;
    czas.next_second();
    std::cout << "kolejna sekunda: " << czas.to_string() << std::endl;
    czas.next_hour();
    std::cout << "kolejna godzina: " << czas.to_string() << std::endl;
    std::cout << "czas do polnocy: " << czas.time_to_midnight().to_string()
              << std::endl;

    std::cout << "drugi obiekt czasu: " << czas2.to_string() << std::endl;
    std::cout << "pora dnia: " << czas2.to_string(czas2.time_of_day())
              << std::endl;
    std::cout << "czas do polnocy: " << czas2.time_to_midnight().to_string()
              << std::endl;

    std::cout << "dodawanie obu obiektów: " << (czas + czas2).to_string()
              << std::endl;

    std::cout << "odejmowanie obu obiektów: " << (czas - czas2).to_string()
              << std::endl;

    return 0;
}
