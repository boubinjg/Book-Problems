#include<iostream>
#include<vector>
int main()
{
	std::vector<int> v{0,1,2}, v2{0,1,2};
	std::cout<<(v==v2)<<std::endl;
	return 0;
}
