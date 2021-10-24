#include <s25441/Time.h>

#include <iomanip>
#include <iostream>
#include <string>
#include <thread>
#include <chrono>

auto ::Time::next_hour() -> void
{
	if(minuta>59)
	{
		godzina++;
	}
	
}

auto ::Time::next_minute() -> void
{
	if(sekunda>59)
        {
            	minuta++;
        }
        return minuta;

}

auto ::Time::next_second() -> void
{
	std::this_thread::sleep_for(std::chrono::seconds(1));
	sekunda++;
	return sekunda;
	
}


auto ::Time::to_string() const -> std::string
{
    return std::to_string(godzina)+":"+std::to_string(minuta)+":"+std::to_string(sekunda);
}

auto main() -> int
{
	auto czas=(23,30,23)
	std::cout<<czas<<std::endl;    


    return 0;
}
