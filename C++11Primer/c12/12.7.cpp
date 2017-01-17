#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
#include<memory>
void print(std::shared_ptr<std::vector<int>>& v)
{
	std::ostream_iterator<int> is(std::cout, " ");
	std::copy(v->cbegin(), v->cend(), is);
	std::cout<<std::endl;
}
void readInts(std::shared_ptr<std::vector<int>>& v)
{
	int i;
	while(std::cin>>i) {
		v->push_back(i);
	}
}
std::shared_ptr<std::vector<int>> retVec() 
{
	return std::make_shared<std::vector<int>>();
}
int main()
{
	auto v = retVec();
	readInts(v);
	print(v);
	
	return 0;
}
