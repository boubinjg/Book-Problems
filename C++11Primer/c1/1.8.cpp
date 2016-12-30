#include<iostream>
int main()
{
	std::cout << "/*"; 
	std::cout << "*/";
	//only line 3 is illegal
	//std::cout << /* "*/" */;
	std::cout<< /* "*/" /* "/*" */;
}
