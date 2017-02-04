#include<string>
#include<memory>
#include<algorithm>
#include<iostream>
#ifndef STRVEC_H
#define STRVEC_H
template <typename T>
class Vec{
public:
	Vec() :
		elements(nullptr), first_free(nullptr), cap(nullptr) {}
	Vec(std::initializer_list<T>);
	Vec(const Vec&);
	Vec& operator=(const Vec&);
	~Vec();

	void push_back(const T&);
	size_t size() const {return first_free - elements; }
	size_t capacity() const {return cap - elements; }
	T* begin() const {return elements; }
	T* end() const {return first_free; } 
	
	template <typename ...Args> inline
	void emplace_back(Args&&... args)
	{chk_n_alloc(); alloc.construct(first_free++, std::forward<Args>(args)...);}
private:
	static std::allocator<T> alloc;
	void chk_n_alloc()
		{if (size() == capacity()) reallocate(); }
	std::pair<T*, T*> alloc_n_copy
		(const T*, const T*);

	void free();
	void reallocate();
	T *elements, *first_free, *cap;
};

#endif
