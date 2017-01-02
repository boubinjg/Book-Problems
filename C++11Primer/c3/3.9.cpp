#include<string>
#include<iostream>
int main()
{
	//this exhibits undefined behavior
	std::string s;
	std::cout<<s[0]<<std::endl;	
	return 0;
}
