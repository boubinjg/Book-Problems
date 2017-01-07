#include<iostream>
#include<initializer_list>
int sum(std::initializer_list<int> i)
{
	int ret = 0;
	for(auto v : i)
		ret += v;
	return ret;
}
int main()
{
	std::cout<<sum({1,2,3,4,5})<<std::endl;
}
