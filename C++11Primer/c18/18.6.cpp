#include<stdexcept>
#include<exception>
#include<iostream>
class exceptionType {};
int main()
{
	try {
		exceptionType *p;
		throw p;
	} catch(exceptionType *pet) {
		std::cout<<"Caught P"<<std::endl;
	}
	
	try{
		throw 10;
	} catch(...) {
		std::cout<<"Caught anything"<<std::endl;
	}
	typedef int EXCPTYPE;
	try {
		EXCPTYPE i = 10;
		throw i;
	} catch(EXCPTYPE) {
		std::cout<<"Caught EXCPTYPE" <<std::endl;
	}
	return 0;
}
