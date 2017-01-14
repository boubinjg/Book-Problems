#include<iostream>
int main()
{
	auto l = [](int i, int j){return i + j;};
	
	std::cout<<l(1,2)<<std::endl;
}
