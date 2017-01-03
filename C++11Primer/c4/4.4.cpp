#include<iostream>
int main()
{
	//16+75 = 91
	//     ((((12 / 3) * 4) + (5 * 15)) + ((24 % 4) / 2))
	int i = 12 / 3 * 4 + 5 * 15 + 24 % 4 / 2;
	std::cout<<i<<std::endl;
	return 0;
}
