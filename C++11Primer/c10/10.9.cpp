#include<iostream>
#include<vector>
#include<algorithm>
int main()
{
	std::vector<int> i{1,1,2,2,3,3,4,4,5,5,5,5,6,8,8};
	
	std::sort(i.begin(), i.end());
	auto it = std::unique(i.begin(), i.end());
	i.erase(it, i.end());
	
	for(auto v : i)
		std::cout<<v<<" ";
	std::cout<<std::endl;
	return 0;
}
