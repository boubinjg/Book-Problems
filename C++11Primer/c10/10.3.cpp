#include<iostream>
#include<vector>
#include<algorithm>
int main()
{
	std::vector<int> v{1,2,3,4,5,6};
	std::cout<<std::accumulate(v.begin(), v.end(), 0)<<std::endl;
	return 0;
}
