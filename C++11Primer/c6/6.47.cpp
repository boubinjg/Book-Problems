#include<vector>
#include<iostream>
#include<cassert>
//#define NDEBUG
void print(std::vector<int>::iterator beg, std::vector<int>::iterator end)
{
	if(beg != end)
	{
		std::cout<<*beg++<<std::endl;
		print(beg, end);
		#ifndef NDEBUG
			std::cout<<"Size of Vector"<<beg-end<<std::endl;
			std::cout<<__func__<<std::endl;
			std::cout<<__LINE__<<std::endl;
			std::cout<<__TIME__<<std::endl;
		#endif
	}
}
int main()
{
	std::vector<int> v = {1,2,3,4,5};
	print(v.begin(), v.end());
	return 0;
}
