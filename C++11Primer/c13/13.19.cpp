#include"13.18.h"
#include<iostream>
int main()
{
	//employee does need to define copy control members. the synthesized assign
	//and copy simply copy the uniqueId value.
	Employee a("asdf");
	Employee b(a);
	Employee c("abcd");
	std::cout<<a.getId()<<" "<<b.getId()<<" "<<c.getId()<<std::endl;
	return 0;
}
