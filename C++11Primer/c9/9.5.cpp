#include<vector>
#include<iostream>
std::vector<int>::iterator
find(std::vector<int>::iterator beg, std::vector<int>::iterator end, int num)
{
	while(beg != end)
	{
		if(*beg == num)
			return beg;
		++beg;
	}
	return end;
}
int main()
{
	std::vector<int> v = {1,2,3,4,5};
	auto pos = find(v.begin(), v.end(), 3);
	if(pos != v.end())
		std::cout<<*pos<<std::endl;
	return 0;
}
