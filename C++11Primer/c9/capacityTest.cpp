#include<iostream>
#include<vector>
int main()
{
	std::vector<int> v;
	int capacity = v.capacity();
	for(int i = 0; i<1000; i++)
	{
		v.push_back(i);
		if(capacity != v.capacity()) {
			std::cout<<v.size()<<" "<<v.capacity()<<std::endl;
			capacity = v.capacity();
		}
	}
	return 0;
}
