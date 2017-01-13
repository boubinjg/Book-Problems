#include<iostream>
#include<vector>
#include<list>
int main()
{
	std::list<int> ial{0,1,1,2,3,5,8,13,21,55,89};
	std::vector<int> iav{0,1,1,2,3,5,8,13,21,55,89};

	auto lit = ial.begin();
	while(lit!=ial.end())
	{
		if(*lit % 2)
			lit = ial.erase(lit);
		else
			++lit;
	}
	for(auto i : ial)
		std::cout<<i<<" ";
	std::cout<<std::endl;
	
	auto vit = iav.begin();
	while(vit!=iav.end())
	{
		if(*vit % 2)
			++vit;
		else
			vit = iav.erase(vit);
	}
	for(auto i : iav)
		std::cout<<i<<" ";
	std::cout<<std::endl;
	

	return 0;
}
