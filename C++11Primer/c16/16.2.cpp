#include<iostream>
template <typename t>
bool compare(const t& lhs, const t& rhs)
{
	return lhs<rhs;
}
int main()
{	
	std::cout<<compare("asdf","asdg")<<" "
	         <<compare(1.2, 3.3)<<std::endl;
	return 0;
}
