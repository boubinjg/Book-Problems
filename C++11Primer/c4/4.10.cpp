#include<iostream>
int main()
{
	int i;
	while(std::cin>>i && i != 42)
	{
		std::cout<<"Nice "<<i<<std::endl;
	}
	return 0;
}
