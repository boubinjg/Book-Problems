#include<vector>
#include<iostream>
bool find(std::vector<int>::iterator beg, std::vector<int>::iterator end, int num)
{
	while(beg != end)
	{
		if(*beg == num)
			return true;
		++beg;
	}
	return false;
}
int main()
{
	std::vector<int> v = {1,2,3,4,5};
	std::cout<<find(v.begin(), v.end(), 6)<<std::endl;
	return 0;
}
