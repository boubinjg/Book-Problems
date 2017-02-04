#include<iostream>
template<typename T, typename ... Args>
void foo(const T& t, const Args& ... rect)
{
	std::cout<<"args: "<< sizeof...(Args) <<"Rect: "<< sizeof...(rect)<<std::endl;
}
int main()
{
	int i = 0;
	double d = 3.14;
	std::string s = "asdf";
	foo(i, s, 42, d);
	foo(s, 42, "hi");
	foo(d, s);
	foo("hi");
	return 0;
}