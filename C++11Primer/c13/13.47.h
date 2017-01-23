#ifndef STR_H
#define STR_H

#include<memory>
#include<algorithm>
#include<iostream>
class String{
	
public:
	String() : String("") {}
	String(const char*);
	String(const String&);
	String& operator=(const String&);
	~String();
	
private:
	std::pair<char*, char*> alloc_n_copy(const char*, const char*);
	void free();
	void init(const char*, const char*);
	char *elements;
	char *end;
	std::allocator<char> alloc;
};
void String::init(const char *first, const char* last)
{
	auto str = alloc_n_copy(first, last);
	elements = str.first;
	end = str.second;
}
String::String(const char* beg)
{
	char *end = const_cast<char*>(beg);
	while(*end) {
		++end;
	}
	init(beg, ++end);
}
String::String(const String& rhs)
{
	init(rhs.elements, rhs.end);	
	std::cout<<"copy"<<std::endl;
}
String& String::operator=(const String& s)
{
	auto data = alloc_n_copy(s.elements, s.end);
	free();
	elements = data.first;
	end = data.second;
	std::cout<<"copy assign"<<std::endl;
	return *this;
}
String::~String()
{
	free();
}
void String::free()
{
	if(elements) {
		std::for_each(elements, end, [this](char &c){alloc.destroy(&c);});
		alloc.deallocate(elements, end-elements);
	}
}
std::pair<char*, char*> 
String::alloc_n_copy(const char* beg, const char* end)
{
	auto data = alloc.allocate(end-beg);
	return {data, std::uninitialized_copy(beg, end, data)};
}
#endif
