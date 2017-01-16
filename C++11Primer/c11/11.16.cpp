#include<iostream>
#include<map>
int main()
{
	std::map<int, int> intMap;
	intMap[0] = 5;
	auto it = intMap.begin();
	it->second = 5;
	std::cout<<(*it).second<<std::endl;
	return 0;
}
