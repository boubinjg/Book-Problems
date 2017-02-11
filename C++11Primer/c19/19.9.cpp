#include<typeinfo>
#include<iostream>
int main()
{
	int i = 0;
	int *ip = &i;
	std::string s = "asdf";
	double d = 0.0;
	
	std::cout<<typeid(i).name() << std::endl
		 <<typeid(ip).name() << std::endl 
		 <<typeid(s).name() << std::endl
		 <<typeid(d).name() << std::endl
		 <<typeid(0.0).name() <<  std::endl;
	return 0;
}
