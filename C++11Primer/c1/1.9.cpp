#include<iostream>
int main()
{
	int i = 50, ret = 0;
	while(i<=100)
	{
		ret += i;
		i++;
	}
	std::cout<<ret<<std::endl;
}
