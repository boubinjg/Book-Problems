#include<iostream>
#include<vector>
int main()
{
	std::vector<int> v1 = {1,2,3,4,5}, 
		         v2 = {1,2,3},
			 v3 = {1,2,3,4,6};

	auto it1 = v1.begin(), it2 = v2.begin(), it3 = v3.begin();
	
	for(; it1 != v1.end() && it2 != v2.end(); ++it1, ++it2)
	{
		if(*it1 != *it2)
		{
			std::cout<<"Not Equal"<<std::endl;
			break;
		}
	}
	if(it1 == v1.end() || it2 == v2.end()) 
		std::cout<<"equal"<<std::endl;
	
	it1 = v1.begin();
	for(; it1 != v1.end() && it3 != v3.end(); ++it1, ++it3)
	{
		if(*it1 != *it3)
		{
			std::cout<<"Not Equal"<<std::endl;
			break;
		}
	}
	if(it1 == v1.end() || it3 == v3.end()) 
		std::cout<<"equal"<<std::endl;


	return 0;
}
