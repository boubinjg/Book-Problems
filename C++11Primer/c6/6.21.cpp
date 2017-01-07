#include<iostream>
//the pointer should be const, as we do not intend to modify it
int comp(const int *i, int j)
{
	if(*i > j)
		return *i;
	return j;
}
int main()
{
	int val = 4;
	int *i = &val, j = 5;
	
	std::cout<<comp(i, j)<<std::endl;

	*i = 10;
	
	std::cout<<comp(i, j)<<std::endl;
	
	return 0;
}
