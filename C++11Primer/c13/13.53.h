#include<string>
#include<iostream>
#ifndef HASPTR_H
#define HASPTR_H
class HasPtr{
	friend void swap(HasPtr&, HasPtr&);
	friend bool operator<(HasPtr&, HasPtr&);
public:
	HasPtr(const std::string &s = std::string()) :
		ps(new std::string(s)), i(0) {}

	HasPtr(const HasPtr& h) :
		ps(new std::string(*(h.ps))), i(h.i) {std::cout<<"copy constructor"<<std::endl;}
	HasPtr& operator=(HasPtr rhs) {
		this->swap(rhs);
		std::cout<<"copy assign"<<std::endl;
		return *this;
	}
	HasPtr(HasPtr&& rhs) noexcept : ps(rhs.ps), i(rhs.i)
	{
		std::cout<<"move constructor"<<std::endl;
		rhs.ps = nullptr;
	}
	HasPtr& operator=(HasPtr&& rhs) noexcept
	{
		ps = rhs.ps;
		i = rhs.i;
		rhs.ps = nullptr;
		std::cout<<"move assign"<<std::endl;
		return *this;
	}
	void swap(HasPtr& r)
	{
		using std::swap;
		swap(ps, r.ps);
		swap(i, r.i);
		std::cout<<"swapped"<<std::endl;
	}
	~HasPtr()
	{
		delete ps;	
	}
private:
	std::string *ps;
	int i;
};
void swap(HasPtr& lhs, HasPtr& rhs)
{
	lhs.swap(rhs);
}
bool operator<(HasPtr& lhs, HasPtr& rhs) { return *(lhs.ps) < *(rhs.ps); }


#endif
