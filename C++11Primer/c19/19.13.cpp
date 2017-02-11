#include"14.2.h"
int main()
{
	Sales_data s("asdf",0,0);
	auto bnp = &Sales_data::bookNo;
	std::cout<<s.*bnp<<std::endl;
	return 0;
}
