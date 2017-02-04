#include<iostream>
#include<vector>
template <typename T, typename ... Args>
std::ostream& print(std::ostream& os, T &t, Args ... rest)
{
	std::cout<<t<<" ";
	print(os, rest...);
}

template <typename T>
std::ostream& print(std::ostream& os, T& t)
{
	os<<t<<std::endl;
}

int main()
{
	std::vector<int> v;
	int i = 0;
	double d = 1.0;
	//since we declared the variadic version above the non-variadic version, it will not
	//be able to deduce a function to call after it has recursed 
	print(std::cout, i,i,i,i,i,i,i);
	print(std::cout, i);
	print(std::cout, i, "hi", d, 0x123);
	print(std::cout, i, i, i);
}
