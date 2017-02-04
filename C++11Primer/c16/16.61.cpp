#include<memory>
#include<string>
#include<iostream>
template<typename T, typename ... Args>
T* make_shared(Args... rest)
{
	return new T(rest...);	
}
int main()
{
	//This just makes a regular pointer, but if used in a shared_ptr class,
	//this template function could create new shared_ptrs
	std::string* s = make_shared<std::string>(10,'c');
	std::cout<<*s<<std::endl;
	delete s;
}
