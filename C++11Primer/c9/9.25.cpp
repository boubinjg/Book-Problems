#include<iostream>
#include<vector>
int main()
{
	std::vector<int> v{1,2,3,4,5};
	//in both situations, nothing happens
	v.erase(v.begin()+1, v.begin()+1);
	for(auto i : v)
		std::cout<<i<<std::endl;
	
	v.erase(v.end(),v.end());
	for(auto i : v)
		std::cout<<i<<std::endl;

}
