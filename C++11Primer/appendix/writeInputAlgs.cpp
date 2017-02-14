#include<iostream>
#include<vector>
#include<algorithm>
void print(std::vector<int> v)
{
	for(auto i : v) 
		std::cout<<i<<" ";
	std::cout<<std::endl;
}
int main()
{
	std::vector<int> v1{1,2,3,4,5,6,7,8,9,10}, v2(10);
	
	//copies v1 to v2
	std::copy(v1.begin(), v1.end(), v2.begin());	
	print(v2);

	std::fill(v2.begin(), v2.end(), 0);

	//copies v1 values that the predicate determines are true to v2
	std::copy_if(v1.begin(), v1.end(), v2.begin(), [](int i){return i%2;});
	print(v2);
	
	//copies n values from v.begin to dest
	std::copy_n(v1.begin()+5, 5, v2.begin()+5);
	print(v2);
	
	std::move(v1.begin(), v1.end(), v2.begin());
	print(v2);
	
	v1 = v2;

	//applies a unary operation on v1 and places it at dest
	std::transform(v1.begin(), v1.end(), v1.begin(), [](int i){return i *= 2;});
	print(v1);

	//applies a binary operation on v1 using v1[i] and v2[i] and places it at dest
	std::transform(v1.begin(), v1.end(), v2.begin(), v2.begin(), [](int i, int j){return i+j;});
	print(v2);

	//replaces instances of oldval with newval, coppies value to dest
	std::replace_copy(v1.begin(), v1.end(), v2.begin(), 2, 100);
	print(v2);
	
	//replace_copy, but with a unary predicate
	std::replace_copy_if(v2.begin(), v2.end(), v1.begin(), [](int i){return i == 100;}, 500);
	print(v1);

	std::sort(v1.begin(), v1.end());
	std::sort(v2.begin(), v2.end());
	std::vector<int> v3;
	auto it = std::back_inserter(v3);
	//merges two sorted sequences, also takes an optional comparator
	std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), it);
	print(v3);
	return 0;
}
