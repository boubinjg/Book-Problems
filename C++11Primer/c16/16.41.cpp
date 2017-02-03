#include<iostream>
#include<algorithm>
#include<type_traits>
template <typename T>
auto sum(T rhs, T lhs) -> decltype(rhs + lhs)
{
	return rhs + lhs;
}
int main()
{
	int i = sum(100, 200);
	std::cout<<i<<std::endl;
	return 0;
}
