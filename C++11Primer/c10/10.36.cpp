#include<iostream>
#include<vector>
#include<algorithm>
int main()
{
	std::vector<int> v{1,2,0,5,0,3,3,3,0};
	auto it = std::find(v.crbegin(), v.crend(), 0);
	//element before the last 0
	std::cout<<*(++it)<<std::endl;
	return 0;
}
