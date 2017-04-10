#include<iostream>
#include<vector>
#include<random>
#include<algorithm>
void print(std::vector<int>& v)
{
	for(auto i : v)
		std::cout<<i<<" ";
	std::cout<<std::endl;
}
int random(int a, int b)
{
	static std::default_random_engine e;
	std::uniform_int_distribution<> r(a,b);
	return r(e);
}
void randomSort(std::vector<int>& v)
{	
	for(int i = 0; i<v.size(); i++) 
		std::swap(v[i], v[random(i,v.size()-1)]);
}
int main()
{
	std::vector<int> v{1,2,3,4,5,6,7,8,9,10};
	randomSort(v);
	print(v);
}
