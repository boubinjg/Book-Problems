#include<memory>
#include<iostream>
#include<vector>
#include<fstream>
#include<exception>
void exercise1(int *b, int *e)
{
	std::vector<int> v(b, e);
	int *p = new int [v.size()];
	std::ifstream in("ints");
	try {

	}catch(std::exception e) {
		delete p;
	}
}

void exercise2(int *b, int *e)
{
	std::vector<int> v(b,e);
	std::shared_ptr<int> p(new int [v.size()]);
	std::ifstream in("ints");
}
int main()
{
	return 0;
}
