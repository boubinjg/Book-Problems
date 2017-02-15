#include<iostream>
#include<algorithm>
#include<vector>
#include<random>
void print(std::vector<int> v)
{
	for(auto i : v)
		std::cout<<i<<" ";
	std::cout<<std::endl;
}
int main()
{
	std::vector<int> v{1,2,3,4,5,6,7}, v2;
	
	//reverses the range, also includes reverse_copy
	std::reverse(v.begin(), v.end());
	print(v);
	
	//random shuffles array, also takes random engine
	std::random_shuffle(v.begin(), v.end());
	print(v); 
	
	//shuffles using a uniform distribution
	std::default_random_engine e;

	return 0;
}
