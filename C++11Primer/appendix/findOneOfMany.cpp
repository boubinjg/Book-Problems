#include<iostream>
#include<algorithm>
#include<vector>
int main()
{
	std::vector<int> v{1,2,3,4,4,5,7,9,9,9};
	
	//find first adjacent pair of the same value
	auto it1 = adjacent_find(v.begin(), v.end());
	std::cout<<*it1<<std::endl;
	
	//finds first adjacent odd values
	auto it2 = adjacent_find(v.begin(), v.end(), [](int i, int j){return i%2 && j%2;});
	std::cout<<*it2<<std::endl;
	
	//finds beginning of range with 3 9s
	auto it3 = search_n(v.begin(), v.end(), 3, 9);
	std::cout<<*it3<<std::endl;

	//finds beginning of range with 5 odd numbers, val (1) is used as the binary pred argument i for all calls.
	auto it4 = search_n(v.begin(), v.end(),5, 1, [](int i, int j){return i%2 && j%2;});
	std::cout<<*it4<<std::endl;
	return 0;
}
