#include <iostream>
#include <string>

auto main() -> int
{
        int a;
        int b;
        int c;
	
        std::cout<<"a = ";
        std::cin>>a;
        std::cout<<"b = ";
        std::cin>>b;

	std:: cout<<"Wybierz 1[dodawanie], 2[odejmowanie], 3[mnozenie], 4[dzielenie]"<<"\n";
	
        std::cout<<"podaj dzialanie: ";
        std::cin>>c;
	
	if(c==1)
	{
	std::cout<<a+b<<"\n";
	}
	else if(c==2)
        {
        std::cout<<a-b<<"\n";
        }
	else if(c==3)
        {
        std::cout<<a*b<<"\n";
        }
	else if(c==4)
        {
        std::cout<<a/b<<"\n";
        }


	return 0;
}
