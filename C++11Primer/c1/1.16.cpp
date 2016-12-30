#include<iostream>
int main()
{
	int cur = 0, ret = 0;
	while(std::cin>>cur)
		ret += cur;
	std::cout<<ret<<std::endl;
	return 0;
}
