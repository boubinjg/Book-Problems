#include<iostream>
#include<algorithm>
#include<vector>
int main()
{
	std::vector<int> v{1,2,3,4,5,6,7,8,9,10,5};
	
	//find five
	auto it1 = std::find(v.begin(), v.end(), 5);
	std::cout<<*it1<<std::endl;
	
	//find first even value
	auto it2 = std::find_if(v.begin(), v.end(), [](int i){return !(i%2);});
	std::cout<<*it2<<std::endl;
	
	//find first odd value
	auto it3 = std::find_if_not(v.begin(), v.end(), [](int i){return !(i%2);});
	std::cout<<*it3<<std::endl;
	
	//count all 5s in the range
	int val = std::count(v.begin(), v.end(), 5);
	std::cout<<val<<std::endl;
	
	//count evens in range
	val = std::count_if(v.begin(), v.end(), [](int i){return !(i%2);});
	std::cout<<val<<std::endl;
	
	//see if all values are even
	bool b = std::all_of(v.begin(), v.end(), [](int i){return !(i%2);});
	std::cout<<std::boolalpha<<b<<std::endl;
	
	//see if any values are even
	b = std::any_of(v.begin(), v.end(), [](int i){return !(i%2);});
	std::cout<<b<<std::endl;

	//see if none of the values are greater than 100
	b = none_of(v.begin(), v.end(), [](int i){return i > 100;});
	std::cout<<b<<std::endl;
	return 0;
}
