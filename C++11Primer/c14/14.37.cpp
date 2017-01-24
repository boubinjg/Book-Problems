#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>
class iseq{
public:
	iseq(int i = 1) : val(i) {}
	bool operator()(int i){ return i==val; }
	int val;
};
int main()
{
	std::vector<int> v{1,3,2,4,1,1,2,1,5,1,6,1,3};
	std::replace_if(v.begin(), v.end(), iseq(1), 0);

	std::ostream_iterator<int> os(std::cout, " ");
	std::copy(v.begin(), v.end(), os);
	std::cout<<std::endl;
}
