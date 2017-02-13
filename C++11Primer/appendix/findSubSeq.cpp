#include<iostream>
#include<algorithm>
#include<vector>
int main()
{
	std::vector<int> v1{1,2,3}, v2{5,6,7,8,3,9,1,2,3};
	
	//find the first position in v2 where all of v1 occurs begins to occur contiguously
	auto it1 = std::search(v2.begin(), v2.end(), v1.begin(), v1.end());
	std::cout<<*it1<<std::endl;
	
	//finds the first position where the elements in v2 are less than the ones in v1
	auto it2 = std::search(v2.begin(), v2.end(), v1.begin(), v1.end(), [](int i, int j){return i>j;});
	std::cout<<*it2<<std::endl;

	//finds the first occurance in v2 of any value in v1
	auto it3 = std::find_first_of(v2.begin(), v2.end(), v1.begin(), v1.end());
	std::cout<<*it3<<std::endl;

	//finds first occurance in v2 where a value is less than a vaulue in v1
	auto it4 = std::find_first_of(v2.begin(), v2.end(), v1.begin(), v1.end(), 
		                     [](int i, int j){return i < j;});
	std::cout<<*it4<<std::endl;

	//find the last position in v2 where all of v1 occurs begins to occur contiguously
	auto it5 = std::find_end(v2.begin(), v2.end(), v1.begin(), v1.end());
	std::cout<<*it5<<std::endl;
	
	//finds the last position where the elements in v2 are less than the ones in v1
	auto it6 = std::find_end(v2.begin(), v2.end(), v1.begin(), v1.end(), [](int i, int j){return i>j;});
	std::cout<<*it6<<std::endl;


	return 0;
}
