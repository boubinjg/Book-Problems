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
	std::vector<int> v{1,2,3,4,5,6,7,8}, v2(8);
	
	//copies from range v.begin to range v.end into range ending at v2.end
	//also has a move_backward version
	std::copy_backward(v.begin(), v.end(), v2.end()); 
	print(v2);
		
	v.insert(v.end(), v2.begin(), v2.end());
	
	//merges two sorted ranges in a vector in place
	//also has a version which takes a comparator
	std::inplace_merge(v.begin(), v.begin()+8, v.end());
	print(v);
	
	return 0;
}
