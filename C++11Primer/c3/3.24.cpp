#include<iostream>
#include<vector>
int main()
{
	int i;
	std::vector<int> v;
	while(std::cin>>i)
		v.push_back(i);
	
	auto mid = v.begin() + v.size()/2;
	std::cout<<std::endl;
	for(auto it = v.begin(); it!=v.end(); it++)
		std::cout<<*it + *(it+1)<<std::endl;
	std::cout<<std::endl;
	for(auto it = v.begin(); it!= mid; it++){
		std::cout<<*it + *(v.begin() + (v.end() - it)-1)<<std::endl;
	}
	return 0;
}
