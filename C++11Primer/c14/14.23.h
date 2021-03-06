#include<string>
#include<memory>
#include<iostream>
#include<algorithm>
#ifndef STRVEC_H
#define STRVEC_H
class StrVec{
public:
	friend bool operator==(StrVec&, StrVec&);
	friend bool operator!=(StrVec&, StrVec&);	
	friend bool operator<(StrVec& lhs, StrVec& rhs);
	friend bool operator<=(StrVec& lhs, StrVec& rhs);
	friend bool operator>(StrVec& lhs, StrVec& rhs);
	friend bool operator>=(StrVec& lhs, StrVec& rhs);
	
	StrVec():
		elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(std::initializer_list<std::string>);
	StrVec(const StrVec&);
	StrVec& operator=(const StrVec&);
	StrVec(StrVec&&) noexcept;
	StrVec& operator=(StrVec&&) noexcept;
	~StrVec();

	void push_back(const std::string&);
	size_t size() const {return first_free - elements; }
	size_t capacity() const {return cap - elements; }
	std::string* begin() const {return elements; }
	std::string* end() const {return first_free; } 
	StrVec& operator=(std::initializer_list<std::string>);
	
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
StrVec& StrVec::operator=(std::initializer_list<std::string> li)
{
	auto data = alloc_n_copy(li.begin(), li.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}
bool operator<(StrVec& lhs, StrVec& rhs)
{
	return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}
bool operator<=(StrVec& lhs, StrVec& rhs)
{
	return !(rhs < lhs);
}
bool operator>(StrVec& lhs, StrVec& rhs)
{
	return rhs < lhs;
}
bool operator>=(StrVec& lhs, StrVec& rhs)
{	
	return !(lhs < rhs);
}	
bool operator==(StrVec& lhs, StrVec& rhs)
{
	std::string *lhscur = lhs.begin(), *rhscur = rhs.begin();
	while(lhscur != lhs.end() && rhscur != rhs.end()) {
		if(*lhscur++ != *rhscur++)
			return false;
	}
	return true;
}
bool operator!=(StrVec& lhs, StrVec& rhs)
{
	return !(lhs == rhs);
}

StrVec::StrVec(StrVec&& mv) noexcept : elements(mv.elements), first_free(mv.first_free), cap(mv.cap)
{
	mv.elements = mv.cap = mv.first_free = nullptr;
}
StrVec& StrVec::operator=(StrVec&& mv) noexcept
{
	if(this != &mv) {
		free();
		elements = mv.elements; cap = mv.cap; first_free = mv.first_free;
		mv.elements = mv.cap = mv.first_free = nullptr;
	}
	return *this;
}

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
		for(auto p = first_free; p!=elements;)
			alloc.destroy(--p);
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
	first_free = cap = data.second;
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
