#include<iostream>
#include<exception>
int main()
{
	int i, j;
	std::cin>>i>>j;
	if(!j)
	{
		std::exception e;
		throw e;
	}
	std::cout<<i/j<<std::endl;
}
