#include<vector>
#include<algorithm>
#include<iostream>
class foo{
public:
	foo sorted() &&;
	foo sorted() const &;
	foo(std::vector<int>);

	std::vector<int> data;
};
foo foo::sorted() &&
{
	std::cout<<"rvalue"<<std::endl;
	std::sort(data.begin(), data.end());
	return *this;
}
foo foo::sorted() const &
{
	std::cout<<"lvalue"<<std::endl;
	return foo(*this).sorted(); //calls rvalue
	//return ret.sorted(); //recurses infinitely
}
foo::foo(std::vector<int> v)
{
	data = v;
}
int main()
{
	std::vector<int> v{1,2,3,-1};
	foo f1(v);
	f1 = f1.sorted();
}
