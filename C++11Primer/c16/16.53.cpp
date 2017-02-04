#include<iostream>
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
	int i = 0;
	double d = 1.0;
	print(std::cout, i,i,i,i,i,i,i);
	print(std::cout, i);
	print(std::cout, i, "hi", d, 0x123);
}
