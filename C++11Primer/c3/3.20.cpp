#include<iostream>
#include<vector>
int main()
{
	int i;
	std::vector<int> v;
	while(std::cin>>i)
		v.push_back(i);
	
	std::cout<<std::endl;
	for(decltype(v.size()) i = 0; i<v.size()-1; i++)
		std::cout<<v[i] + v[i+1]<<std::endl;
	std::cout<<std::endl;
	for(decltype(v.size()) i = 0; i<v.size()/2; i++)
		std::cout<<v[i] + v[v.size()-i-1]<<std::endl;
	
	return 0;
}
