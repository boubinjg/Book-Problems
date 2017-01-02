#include<iostream>
int main()
{
	const char ca[] = {'h','e','l','l','o'};
	const char *cp = ca;
	//because ca is not null terminated, this has undefined behavior
	while(*cp)
	{
		std::cout<<*cp<<std::endl;
		++cp;
	}
	return 0;
}
