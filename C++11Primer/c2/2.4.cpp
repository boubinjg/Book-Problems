#include<iostream>
int main()
{
	unsigned u = 10, u2 = 42;
	//32
	std::cout << u2 - u << std::endl;
	//large positive #
	std::cout << u - u2 << std::endl;
	
	int i = 10, i2 = 42;
	//32
	std::cout << i2 - i << std::endl;
	//-32
	std::cout << i - i2 << std::endl;

	//0
	std::cout << i - u << std::endl;
	//0
	std::cout << u - i << std::endl;
}
