#include"14.2.h"
int main()
{
	Sales_data s("asdf",0,0);
	auto mp = &Sales_data::averagePrice;
	std::cout<<(s.*mp)()<<std::endl;
	return 0;
}
