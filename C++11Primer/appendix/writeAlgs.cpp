#include<iostream>
#include<vector>
#include<algorithm>
void print(const std::vector<int>& v)
{
	for(auto i : v)
		std::cout<<i<<" ";
	std::cout<<std::endl;
}
int main()
{
	std::vector<int> v(10);
	
	//fills the range with a given value;
	std::fill(v.begin(), v.end(), 5);
	print(v);	

	//places n values in the rande beginning at v.begin()
	std::fill_n(v.begin(), 5, 8);
	print(v);
	
	std::default_random_engine e1(100), e2(200);
	
	//fills the range with a generated value 
	std::generate(v.begin(), v.end(), e1);
	print(v);

	//fills the range with n generated values
	std::generate_n(v.begin(), 5, e2);
	print(v);	

	return 0;
}
