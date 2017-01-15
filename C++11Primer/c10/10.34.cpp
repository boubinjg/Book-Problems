#include<iostream>
#include<vector>
#include<iterator>
int main()
{
	std::vector<int> v{1,2,3,4,5,6};
	std::ostream_iterator<int> os(std::cout, " ");
	std::copy(v.crbegin(), v.crend(), os);
	std::cout<<std::endl;
}
