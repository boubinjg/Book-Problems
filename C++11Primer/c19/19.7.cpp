#include"19.6.h"
int main()
{
	QueryBase *p = new AndQuery;
	AndQuery a;
	AndQuery &q = a;
	auto bp = dynamic_cast<AndQuery&>(*p);
	if(typeid(q) == typeid(bp))
		std::cout<<"true"<<std::endl;
	return 0;
}
