#include<iostream>
int fact()
{
	int i, ret = 1;
	std::cout<<"Enter a number"<<std::endl;
	std::cin>>i;

	while(i > 1)
		ret *= i--;
	
	std::cout<<ret<<std::endl;
}
int main()
{
	fact();
	return 0;
}
