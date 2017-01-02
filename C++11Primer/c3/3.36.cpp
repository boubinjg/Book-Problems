#include<iostream>
#include<vector>
int main()
{
	std::vector<int> i = {1,2,3,4,5};
	std::vector<int> i2 = {1,2,3,4,5};
	std::vector<int> i3 = {1,2,3,4};

	//vector comparison is much easier than array comparison

	std::cout<<(i == i2)<<" "<<(i == i3)<<std::endl;

	return 0;
}
