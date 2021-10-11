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
	std::cout<<"c = ";
        std::cin>>c;
        
	if((a>=b) && (a>=c))
	{
		if(b*b+c*c==a*a){
        	std :: cout <<"jest pitagorejski"<<"\n";
        	}
		else
		{
		std :: cout <<"nie jest pitagorejski"<<"\n";
		}
	}
	else if((b>=a) && (b>=c))
        {
                if(a*a+c*c==b*b){
                std :: cout <<"jest pitagorejski"<<"\n";
                } 
                else
                {
                std :: cout <<"nie jest pitagorejski"<<"\n";
                }
        }
	else if((c>=a) && (c>=b))
        {
                if(a*a+b*b==c*c){
                std :: cout <<"jest pitagorejski"<<"\n";
                } 
                else
                {
                std :: cout <<"nie jest pitagorejski"<<"\n";
                }
        }  

	return 0;
}

