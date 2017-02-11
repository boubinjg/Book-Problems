#include"19.6.h"
int main()
{
	QueryBase *p = nullptr;
	AndQuery *q = nullptr;
	if(typeid(q) == typeid(dynamic_cast<AndQuery*>(p)))
		std::cout<<"true"<<std::endl;
	return 0;
}
