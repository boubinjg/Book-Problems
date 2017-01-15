#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>
int main()
{
	std::vector<int> v{0,1,2,3,4,5,6,7,8,9}, newv;
	std::ostream_iterator<int> os(std::cout, " ");
	std::copy(v.crbegin()+2, v.crbegin()+7, std::back_inserter(newv));
	std::copy(newv.begin(), newv.end(), os);
	std::cout<<std::endl;
}
