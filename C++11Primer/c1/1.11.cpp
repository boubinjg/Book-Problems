#include<iostream>
#include<algorithm>
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
