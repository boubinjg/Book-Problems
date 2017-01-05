#include<iostream>
#include<string>
int main()
{
	std::string s, last_s;
	while(s = "", std::cin>>s)
	{
		if(s == last_s)
		{
			std::cout<<s<<std::endl;
			break;
		}
		last_s = s;
	}
	if(s != last_s)
		std::cout<<"no repeats"<<std::endl;
}
