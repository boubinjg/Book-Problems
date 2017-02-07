#include<exception>
#include<cstdlib>
#include<iostream>
#include<stdexcept>
int main()
{
	std::exception_ptr eptr;
	try{
		throw std::logic_error("test");
	} catch(...) {
		eptr = std::current_exception();
	}
	
	try {
		std::rethrow_exception(eptr);
	} catch(const std::exception& e) {
		std::cout<<e.what()<<std::endl;
	}

	return 0;
}
