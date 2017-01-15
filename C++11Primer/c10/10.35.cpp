#include<iostream>
#include<vector>
#include<iterator>
int main()
{
	std::vector<int> v{1,2,3,4,5,6};
	std::ostream_iterator<int> os(std::cout, " ");
	auto it = v.end();
	do{
		--it;
		os = *it;
	}while(it != v.begin());
	std::cout<<std::endl;
}
