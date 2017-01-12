#include<iostream>
#include<list>
#include<vector>
int main()
{
	std::list<int> l {1,2,3};
	std::vector<int> v{1,2,3};

	std::cout<< (std::vector<int>(l.begin(), l.end()) == v) <<std::endl;
	return 0;
}
