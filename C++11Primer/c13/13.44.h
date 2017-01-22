#ifndef STR_H
#define STR_H

#include<memory>
#include<algorithm>

class String{
	
public:
	String() : String("") {}
	String(char*);
	String(String&);
	String& operator=(const String&);
	~String();
		
private:
	std::pair<char*, char*> alloc_n_copy(char*, char*);
	void free();
	
	char *elements;
	char *end;
	std::allocator<char> alloc;
};

String::String(char* cstring)
{
	char *beg = cstring, *end = cstring;
	while(end)
		++end;
	auto p = alloc_n_copy(beg, end);
	elements = p.first;
	end = p.second;
}
String::String(String& s)
{
	auto p = alloc_n_copy(s.elements, s.end);
	elements = p.first;
	end = p.second;	
}
String& String::operator=(const String& s)
{
	auto data = alloc_n_copy(s.elements, s.end);
	free();
	elements = data.first;
	end = data.second;
	return *this;
}
String::~String()
{
	free();
}
void String::free()
{
	if(elements) 
		for(auto p = end; p!=elements;)
			alloc.destroy(--p);
	alloc.deallocate(elements, end-elements);
}
std::pair<char*, char*> 
String::alloc_n_copy(char* beg, char* end)
{
	auto data = alloc.allocate(end-beg);
	return {data, std::uninitialized_copy(beg, end, data)};
}
#endif
