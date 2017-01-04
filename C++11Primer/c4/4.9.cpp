#include<iostream>
int main()
{
	//This will print true, because both the const char cp and char *cp are converted to 
	//bools which evaluate to true

	const char *cp = "Hello World";
	if(cp && *cp)
		std::cout<<"true"<<std::endl;
	else
		std::cout<<"false"<<std::endl;
	return 0;
}
