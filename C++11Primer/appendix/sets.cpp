#include<iostream>
#include<algorithm>
#include<vector>
void print(std::vector<int> v)
{
	for(auto i : v)
		std::cout<<i<<" ";
	std::cout<<std::endl;
}
int main()
{
	std::vector<int> v1{1,2,3,4,5,6,7,8}, v2{2,4,6,8}, v3;
	
	//returns true if all values in the second container are in the first.
	bool b = std::includes(v1.begin(), v1.end(), v2.begin(), v2.end());
	std::cout<<std::boolalpha<<b<<std::endl;

	auto it = std::back_inserter(v3);
	//places the unioin in dest
	std::set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), it);
	print(v3);
	v3.clear();

	//places the intersection in dest
	std::set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), it);
	print(v3);
	v3.clear();
	
	//places the set difference in dest
	std::set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), it);
	print(v3);
	v3.clear();

	//places he symetric difference in dest
	std::set_symmetric_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), it);
	print(v3);

	
	return 0;
}
