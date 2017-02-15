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
	std::vector<int> v{1,2,3,4,5,6,7}, v2;
	
	//removes a value from a vector;
	std::remove(v.begin(), v.end(), 5);
	print(v);

	//removes a value if a condition is met;
	auto it = std::remove_if(v.begin(), v.end(), [](int i){return i == 7;});
	print(std::vector<int>(v.begin(), it));

	auto back = std::back_inserter(v2);

	//copies the range to dest with val removed
	std::remove_copy(v.begin(), v.end(), back, 4);
	print(v2);

	std::remove_copy_if(v.begin(), v.end(), back, [](int i){return !i%2;});
	print(v2);

	std::vector<int> v3{1,1,2,2,3,3,4,4};
	
	//reorders the range so begin to it contain unique values
	auto it2 = std::unique(v3.begin(), v3.end());
	print(std::vector<int>(v3.begin(), it2));
	
	//copies the unique range to dest
	std::unique_copy(v3.begin(), v3.end(), v2.begin());
	print(v2);

	//sets element at mid to the first element, then elements between mid and end, then elements from beg to mid
	std::rotate(v.begin(), v.end() -5, v.end());
	print(v);
	//also has rotate_copy
	
	
	return 0;
}
