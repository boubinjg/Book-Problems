#include<algorithm>
#include<vector>
#include<iostream>
int main()
{
	//returns the min or max of the value or initializer list 
	std::cout<<std::min(5,6)<<std::endl;
	std::cout<<std::min({1,2,3,4,5,6})<<std::endl;
	std::cout<<std::max(5,6)<<std::endl;
	std::cout<<std::max({1,2,3,4,5,6})<<std::endl;

	//returns a pair to the min and max of the values or initializer list
	auto p1 = std::minmax(5,3);
	std::cout<<p1.first<<" "<<p1.second<<std::endl;
	auto p2 = std::minmax({1,2,3,4,5,6});
	std::cout<<p2.first<<" "<<p2.second<<std::endl;

	std::vector<int> v{1,2,3,4,5,6};

	//returns iterators to the min or max element in the range
	std::cout<<*min_element(v.begin(), v.end())<<std::endl;
	std::cout<<*max_element(v.begin(), v.end())<<std::endl;
	
	//returns the iterators to the min and max of the elements in the range as a pair
	auto p3 = std::minmax_element(v.begin(), v.end());
	std::cout<<*p3.first<<" "<<*p3.second<<std::endl;

	return 0;
}
