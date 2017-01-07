#include<iostream>
int fact(int i)
{
	int ret = 1;
	while(i > 1)
		ret *= i--;
	
	return ret;
}
int main()
{
	std::cout<<fact(5)<<std::endl;
	return 0;
}
