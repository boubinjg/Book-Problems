#include<iostream>
int main()
{
	int i = 10;
	auto l = [i](int j){return i + j;};

	std::cout<<l(5)<<std::endl;
	return 0;
}
