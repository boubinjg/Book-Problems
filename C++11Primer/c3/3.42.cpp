#include<iostream>
#include<vector>
int main()
{
	int i[5];
	std::vector<int> v = {1,2,3,4,5};
	
	int *cur = i;
	for(auto it = v.begin(); it!=v.end(); it++)
	{
		*cur = *it;
		cur++;
	}
	cur = i;
	while(cur != std::end(i))
	{
		std::cout<<*cur<<std::endl;
		cur++;
	}
	return 0;
}
