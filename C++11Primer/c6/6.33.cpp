#include<vector>
#include<iostream>
void print(std::vector<int>::iterator beg, std::vector<int>::iterator end)
{
	if(beg != end)
	{
		std::cout<<*beg++<<std::endl;
		print(beg, end);
	}
}
int main()
{
	std::vector<int> v = {1,2,3,4,5};
	print(v.begin(), v.end());
	return 0;
}
