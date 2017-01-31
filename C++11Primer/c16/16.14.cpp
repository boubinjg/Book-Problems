#include"16.14.h"
#include<iostream>
int main()
{
	Screen<3,4> s('a');
	std::cout<<s.getLoc(0,0)<<std::endl;
}
