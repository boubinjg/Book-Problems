#include"16.28.h"
void del(int* p)
{
	std::cout<<"new deleter"<<std::endl;
	delete p;
}
int main()
{
	Shared_ptr<int> p(new int);
	p = 5;
	p.addDel(del);
	std::cout<<p.get()<<std::endl;
	Shared_ptr<int> p2(p);
	p2.addDel(del);
	p2 = 6;
	std::cout<<p.get()<<std::endl;

	return 0;
}
