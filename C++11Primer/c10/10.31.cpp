#include<iostream>
#include<iterator>
#include<vector>
#include<algorithm>
int main()
{
	std::istream_iterator<int> in(std::cin), eof;
	std::vector<int> v(in, eof);
	std::sort(v.begin(), v.end());
	
	auto un = std::unique(v.begin(), v.end());
	v.erase(un, v.end());	

	std::ostream_iterator<int> out(std::cout, " ");
	std::copy(v.begin(), v.end(), out);
	std::cout<<std::endl;
	return 0;
}
