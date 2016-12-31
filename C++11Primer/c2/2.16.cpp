#include<iostream>
int main()
{
	int i = 0, &r1 = i;
	double d = 0, &r2 = d;
	
	r2 = 3.14;
	std::cout<<r2<<std::endl;
	r2 = r1;
	std::cout<<r2<<std::endl;
	i = r2;
	std::cout<<i<<std::endl;
	r1 = d;
	std::cout<<r2<<std::endl;
}
