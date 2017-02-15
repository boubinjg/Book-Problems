#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
void print(std::vector<int> v)
{
	for(auto i : v)
		std::cout<<i<<" ";
	std::cout<<std::endl;
}
int main()
{
	std::vector<int> v{1,2,3,4,5}, v2;

	//returns the sum of all elements in the range
	int i = std::accumulate(v.begin(), v.end(), 0);
	std::cout<<i<<std::endl;
	

	//adds the products of all elements in range 1 with all elements in range 2
	i = std::inner_product(v.begin(), v.end(), v.begin(), 0);
	std::cout<<i<<std::endl;

	auto back = std::back_inserter(v2);
	
	//places the sum at each point into the new range 
	std::partial_sum(v.begin(), v.end(), back);
	print(v2); 
	v2.clear();

	//writes the difference between the current and previous elements to the new range
	std::adjacent_difference(v.begin(), v.end(), back);
	print(v2); 
	v2.clear();

	//sets the first element in range to val, next to val+1, val+2...
	std::iota(v.begin(), v.end(), 5);
	print(v);

	return 0;
}
