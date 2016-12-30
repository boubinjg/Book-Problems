#include<iostream>
#include<algorithm>
//the program in 1.11 already works when the first number is smaller than the second,
//so this is a copy of 1.11
int main()
{
	int first = 0, second = 0;
	std::cout<<"Enter two integers"<<std::endl;
	std::cin>>first>>second;
	int i = std::max(first,second);
	while(i >= std::min(first, second))
	{
		std::cout<<i<<std::endl;
		i--;
	}
}
