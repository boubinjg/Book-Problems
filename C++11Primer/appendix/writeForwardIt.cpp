#include<algorithm>
#include<vector>
#include<iostream>
void print(std::vector<int> v)
{
	for(auto i : v)
		std::cout<<i<<" ";
	std::cout<<std::endl;
}
int main()
{
	std::vector<int> v{1,2,3,4,5,6,7,8};
	
	//swaps the values denoted at the two iterators;
	std::iter_swap(v.begin(), v.end()-1);
	print(v);

	//swaps the range from bed to end, places it at beg2
	std::swap_ranges(v.end()-3, v.end(), v.begin());
	print(v);
	
	//replaces all vals with newval in the range
	std::replace(v.begin(), v.end(), 8, 5000);
	print(v);
	
	//replaces all values for which the predicate is true with the new value
	std::replace_if(v.begin(), v.end(), [](int i){return i%2;}, 1000000);
	print(v);
	return 0;
}
