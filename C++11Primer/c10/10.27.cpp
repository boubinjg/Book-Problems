#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
int main()
{
	std::vector<int> v{1,1,2,2,3,3,4,4,5,5,5,5,5,6,6};
	std::list<int> l;
	std::unique_copy(v.begin(), v.end(), std::inserter(l, l.begin()));
	for(auto i : l)
		std::cout<<i<<std::endl;
	return 0;
}
