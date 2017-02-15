#include<algorithm>
#include<vector>
#include<iostream>
#include<string>
template <typename T>
void print(std::vector<T> v)
{
	for(auto t : v)
		std::cout<<t<<" ";
	std::cout<<std::endl;
}
int main()
{
	std::vector<int> v{1,5,7,2,3,1,76,50,500}, v2 = v, v3 = v;
	
	//sorts the range
	std::sort(v.begin(), v.end());
	print(v);
	
	std::vector<std::string> vs{"a", "b", "c", "ab", "ac", "ad"};
	
	//sorts the range, maintaining the current sorted order
	std::stable_sort(vs.begin(), vs.end());
	print(vs);

	//determines whether range is sorted
	bool b = std::is_sorted(v.begin(), v.end());
	std::cout<<std::boolalpha<<b<<std::endl;

	//returns an iterator to the first value that is not sorted
	auto it = std::is_sorted_until(v2.begin(), v2.end());
	std::cout<<*it<<std::endl;

	//sorts the range from beginning to mid by putting the smallest n (mid-begin) values into
	//the range.
	std::partial_sort(v2.begin(),v2.begin()+5, v2.end());
	print(v2);

	//sorts the input range and puts as much as will fit into the output range.
	std::partial_sort_copy(v3.begin(), v3.end(), v2.begin(), v2.end());
	print(v2);

	auto it2 = v.begin() + 5;
	std::nth_element(v.begin(), it2, v.end());
	std::cout<<*it2<<std::endl;

	return 0;
}
