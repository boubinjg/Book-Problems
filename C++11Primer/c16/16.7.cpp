#include<iostream>
template<typename t, unsigned sz>
constexpr unsigned size(const t (&arr)[sz])
{
	return sz;
}
int main()
{
	int i[] = {1,2,3,2,1};
	std::cout<<size(i)<<std::endl;
	return 0;
}
