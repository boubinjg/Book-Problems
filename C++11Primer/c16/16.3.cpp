#include<iostream>
#include"14.2.h"
template <typename t>
bool compare(const t& lhs, const t& rhs)
{
	return lhs<rhs;
}
int main()
{	
	Sales_data s1, s2;
	compare(s1, s2);
	return 0;
}
