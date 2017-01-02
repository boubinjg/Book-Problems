#include<iostream>
#include<string>
int main()
{
	std::string line, ret = "";
	while(getline(std::cin, line))
	{
		ret += line + " ";
	}
	std::cout<<ret<<std::endl;
}
