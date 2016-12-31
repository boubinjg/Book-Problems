#include<iostream>
int main()
{
	int *p=nullptr, i1 = 5, i2 = 10;
	p = &i1;

	std::cout<<*p<<std::endl;
	i1 = 50;
	std::cout<<*p<<std::endl;
	*p = i2;
	std::cout<<*p<<std::endl;
	std::cout<<i1<<std::endl;
}
