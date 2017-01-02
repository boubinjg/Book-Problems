#include<iostream>
#include<vector>
int main()
{
	std::vector<int> v;
	for(decltype(v.size()) i = 0; i<10; i++)
		v.push_back(i);

	for(auto it = v.begin(); it!= v.end(); it++)
		*it *=2;
	
	for(auto it = v.cbegin(); it!= v.cend(); it++)
		std::cout<<*it<<std::endl;

	return 0;
}
