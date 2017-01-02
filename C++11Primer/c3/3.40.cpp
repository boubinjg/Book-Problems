#include<iostream>
#include<string>
#include<cstring>
int main()
{
	const char cs1[] = "cstring1";
	const char cs2[] = "cstring2";
	char cs3[17];

	std::strcpy(cs3, cs1);
	std::strcat(cs3, cs2);

	std::cout<<cs3<<std::endl;
}
