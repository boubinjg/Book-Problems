#include<iostream>
int main()
{
	//this program creates a pointer *p to int i. it then uses p to store i^2 in i.
	int i = 42;
	int *p = &i;
	*p = *p * *p;
	std::cout<<*p<<std::endl;
}
