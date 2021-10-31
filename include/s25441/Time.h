
#include <iostream>
#include <string>

struct Time {
    int godzina;
    int minuta;
    int sekunda;

    auto to_string() const -> std::string;
    auto next_hour() -> void;
    auto next_minute() -> void;
    auto next_second() -> void;

    enum class Time_of_day { Niezdefiniowany, Rano, Dzien, Wieczor, Noc };

    auto time_of_day() const -> Time_of_day;
    auto to_string(Time_of_day) -> std::string;

    auto operator+(Time const&) const -> Time;
    auto operator-(Time const&) const -> Time;
    auto operator<(Time const&) const -> bool;
    auto operator>(Time const&) const -> bool;
    auto operator==(Time const&) const -> bool;
    auto operator!=(Time const&) const -> bool;

    auto count_seconds() const -> uint64_t;
    auto count_minutes() const -> uint64_t;
    auto time_to_midnight() const -> Time;


    Time(int godzina, int minuta, int sekunda);
};
