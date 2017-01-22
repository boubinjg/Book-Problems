#include<string>
#include<memory>
#include<algorithm>
#ifndef STRVEC_H
#define STRVEC_H
class StrVec{
public:
	StrVec():
		elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(std::initializer_list<std::string>);
	StrVec(const StrVec&);
	StrVec& operator=(const StrVec&);
	~StrVec();

	void push_back(const std::string&);
	size_t size() const {return first_free - elements; }
	size_t capacity() const {return cap - elements; }
	std::string* begin() const {return elements; }
	std::string* end() const {return first_free; } 
	
private:
	static std::allocator<std::string> alloc;
	void chk_n_alloc()
		{if (size() == capacity()) reallocate(); }
	std::pair<std::string*, std::string*> alloc_n_copy
		(const std::string*, const std::string*);

	void free();
	void reallocate();
	std::string *elements, *first_free, *cap;
};
std::allocator<std::string> StrVec::alloc;
StrVec::StrVec(std::initializer_list<std::string> lst)
{
	for(auto i : lst)
		push_back(i);
}
void StrVec::push_back(const std::string& s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}
std::pair<std::string*, std::string*>
StrVec::alloc_n_copy(const std::string *b, const std::string *e)
{
	auto data = alloc.allocate(e-b);
	return {data, std::uninitialized_copy(b, e, data)};
}
void StrVec::free()
{
	if(elements) {
		//I prefer this implementation. I feel that it is more compact and versitile.
		std::for_each(first_free, elements, [](std::string* p){alloc.destroy(--p);});
		alloc.deallocate(elements, cap-elements);
	}
}
StrVec::StrVec(const StrVec &s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}
StrVec::~StrVec() { free(); }
StrVec& StrVec::operator=(const StrVec &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	elements = cap = data.second;
	return *this;
}
void StrVec::reallocate()
{
	auto newcapacity = size() ? 2 * size() : 1;
	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;
	auto elem = elements;
	for(size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}
#endif
