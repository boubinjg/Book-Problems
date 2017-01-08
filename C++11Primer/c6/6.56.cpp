#include<vector>
#include<iostream>
int add(int i, int j)
{
	return i + j;
}
int sub(int i, int j)
{
	return i - j;
}
int mul(int i, int j)
{
	return i * j;
}
int divide(int i, int j)
{
	return i/j;
}
int main()
{
	using ifunc = decltype(add);	
	std::vector<ifunc*> v;
	v.push_back(&add);
	v.push_back(&sub);
	v.push_back(&mul);
	v.push_back(&divide);
	
	int i = 10, j = 2;
	for(auto f : v)
	{
		std::cout<<f(i,j)<<std::endl;
	}	

	return 0;
}
