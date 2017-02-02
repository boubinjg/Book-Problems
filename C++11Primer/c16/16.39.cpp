#include<iostream>
template <typename T>
bool compare(const T rhs, const T lhs)
{
	return rhs<lhs;
}
int main()
{
	std::cout<<compare("asdf", "asdfasdf")<<std::endl;
	return 0;
}
