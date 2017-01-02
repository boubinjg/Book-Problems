#include<iostream>
#include<string>
int main()
{
	//this is legal, c is a reference to a const char
	const std::string s = "Keep Out!";
	for(auto &c : s)
	{
		std::cout<<c<<std::endl;
	}
}
