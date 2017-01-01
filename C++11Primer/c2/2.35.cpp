#include<iostream>
int main()
{
	const int i = 42;
	auto j = i; //j is an int, i's const is remove
	const auto &k = i; //k is a const reference to an int
	auto *p = &i; //p is a referenc to a const int
	const auto j2 = i; //j2 is a const int
	const auto &k2 = i; //k2 is a const reference to an int

	j = 0;
	//k = 0;
	//*p = 0
	//j2 = 0;
	//k2 = 0;
}
