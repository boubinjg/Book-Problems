#include<iostream>
int main()
{
	//both output 4, but d is a reference where as c is not
	int a = 3, b = 4;
	decltype(a) c = a;
	decltype((b)) d = a;
	++c;
	++d;
	std::cout<<c<<" "<<d<<std::endl;
}
