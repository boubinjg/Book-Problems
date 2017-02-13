#include<iostream>
#include<algorithm>
#include<vector>
int main()
{
	std::vector<int> v{1,2,3,4,5,6};
	std::vector<int> v2{1,2,3,4,7,9};
	
	//prints elements in the vector
	std::for_each(v.begin(), v.end(), [](int i){std::cout<<i<<std::endl;});

	//finds first elements in v and v2 that dont match
	auto itPair = std::mismatch(v.begin(), v.end(), v2.begin());
	std::cout<<*(itPair.first)<<" "<<*(itPair.second)<<std::endl;	

	//finds first elements in v and v2 for which the lambda returns false
	auto itPair2 = std::mismatch(v.begin(), v.end(), v2.begin(), [](int i, int j){return i%2 == j%2;});
	std::cout<<*(itPair2.first)<<" "<<*(itPair2.second)<<std::endl;

	//sees if the ranges are equal
	bool b = std::equal(v.begin(), v.end(), v2.begin());
	std::cout<<std::boolalpha<<b<<std::endl;

	//sees if the ranges are equal based on the binary predicate
	b = std::equal(v.begin(), v.end(), v2.begin(), [](int i, int j){return i<=j;});
	std::cout<<b<<std::endl;
	
	return 0;
}
