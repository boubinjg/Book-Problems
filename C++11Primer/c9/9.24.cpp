#include<vector>
#include<iostream>
int main()
{
	std::vector<int> v{1,2,3,4};
	std::vector<int> ve;
	
	std::cout<<v.at(0)<<std::endl;
	std::cout<<v.front()<<std::endl;
	std::cout<<v[0]<<std::endl;
	std::cout<<*(v.begin())<<std::endl;

	std::cout<<ve.at(0)<<std::endl;
	std::cout<<ve.front()<<std::endl;
	std::cout<<ve[0]<<std::endl;
	std::cout<<*(ve.begin())<<std::endl;


	return 0;
}
