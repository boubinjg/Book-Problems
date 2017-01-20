#include<iostream>
#include<vector>
struct x{
	x() {std::cout<< "x()" <<std::endl;}
	x(const x& rhs) {std::cout<<"x(const x&)" << std::endl;};
	x& operator=(x& rhs) {std::cout<<"x&=(x& rhs)"<<std::endl;}
	~x() {std::cout<<"~x" <<std::endl;}
};
int main()
{
	x test;
	x* testptr = &test;
	x test2 = test;
	std::vector<x> xvec;
	x test3(test);
	test = test2;
	return 0;
}
