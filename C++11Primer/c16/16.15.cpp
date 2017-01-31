#include"16.15.h"
#include<iostream>
int main()
{
	Screen<3,4> s('a');
	std::cout<<s<<std::endl;
	Screen<3,5> s2;
	std::cin>>s2;
	std::cout<<s2<<std::endl;
}
