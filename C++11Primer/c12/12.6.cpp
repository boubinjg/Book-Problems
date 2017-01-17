#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
void print(std::vector<int>*& v)
{
	std::ostream_iterator<int> is(std::cout, " ");
	std::copy(v->cbegin(), v->cend(), is);
	std::cout<<std::endl;
}
void readInts(std::vector<int>*& v)
{
	int i;
	while(std::cin>>i) {
		v->push_back(i);
	}
}
std::vector<int>* retVec()
{
	std::vector<int>* v = new std::vector<int>;
	return v;
}
int main()
{
	auto v = retVec();
	readInts(v);
	print(v);
	delete v;
	return 0;
}
