#include<iostream>
#include<vector>
#include<list>
int main()
{
	std::vector<int> vi{1,2,3};
	std::list<int> l(vi.begin(), vi.end());
	std::vector<double> vd(l.begin(), l.end());
	for(auto d : vd)
		std::cout<<d<<std::endl;
}
