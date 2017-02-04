#include<iostream>
#include<vector>
template <typename T>
std::ostream& print(std::ostream& os, T& t)
{
	os<<t<<std::endl;
}
template <typename T, typename ... Args>
std::ostream& print(std::ostream& os, T &t, Args ... rest)
{
	std::cout<<t<<" ";
	print(os, rest...);
}
int main()
{
	std::vector<int> v;
	int i = 0;
	double d = 1.0;
	print(std::cout, i,i,i,i,i,i,i);
	print(std::cout, i);
	print(std::cout, i, "hi", d, 0x123);
	//this will cause an error, because v does not have an overloaded << operator
	print(std::cout, i, v);
}
