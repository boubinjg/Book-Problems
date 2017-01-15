#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
int main()
{
	std::vector<int> v1{1,2,3,4,5,6,7,8,9};
	std::list<int> v2;
	std::vector<int> v3,v4;
	//9 8 7 6 5 4 3 2 1
	std::copy(v1.begin(), v1.end(), std::front_inserter(v2));
	//1 2 3 4 5 6 7 8 9 
	std::copy(v1.begin(), v1.end(), std::back_inserter(v3));
	//1 2 3 4 5 6 7 8 9
	std::copy(v1.begin(), v1.end(), std::inserter(v4, v4.begin()));
	
	for(auto i : v2)
		std::cout<<i<<" ";
	std::cout<<std::endl;
	
	for(auto i : v3)
		std::cout<<i<<" ";
	std::cout<<std::endl;

	for(auto i : v4)
		std::cout<<i<<" ";
	std::cout<<std::endl;

	return 0;
}
