#include<iostream>
#include<vector>
int main()
{
	int i[5] = {1,2,3,4,5};
	std::vector<int> v;
	
	int *cur = i;
	while(cur != std::end(i))
	{
		v.push_back(*cur);
		cur++;	
	}

	for(auto i : v)
		std::cout<<i<<std::endl;
	return 0;
}
