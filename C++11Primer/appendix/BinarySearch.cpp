#include<iostream>
#include<algorithm>
#include<vector>
int main()
{
	//these algorithms all can also accept a comparator
	std::vector<int> v{1,2,3,4,5,6,7,8,9,10};
	
	//returns an iterator to the first elemnt that val is not less than
	auto it1 = std::lower_bound(v.begin(), v.end(), 5);
	std::cout<<*it1<<std::endl;
		

	//returns an iterator to the first element that is greater than than val
	auto it2 = std::upper_bound(v.begin(), v.end(), 5);
	std::cout<<*it2<<std::endl;

	//returns the pair of iterators returned from upper and lower bound
	auto itPair = std::equal_range(v.begin(), v.end(), 5);
	std::cout<<*itPair.first<<" "<<*itPair.second<<std::endl;

	//returns whether a value is in the range
	bool b = std::binary_search(v.begin(), v.end(), 5);
	std::cout<<std::boolalpha<<b<<std::endl;


	return 0;
}
