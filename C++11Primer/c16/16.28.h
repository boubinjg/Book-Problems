#include<utility>
#include<iostream>
#include<functional>
template <typename T> 
class Shared_ptr{
	
public:	
	Shared_ptr() : ptr(new T), refCount(1) {}
	Shared_ptr(T* p) : ptr(p), refCount(1) {}
	Shared_ptr(Shared_ptr& p) : ptr(p.ptr), refCount(p.refCount)  
	{
		if(p.ptr==ptr) { 
			refCount++;
		}
	} 
	Shared_ptr(Shared_ptr&& p) : ptr(std::move(p.ptr)), refCount(std::move(p.refCount))
		{p.ptr = nullptr;}
	Shared_ptr& operator=(const Shared_ptr& p) 
	{
		if(p.ptr != ptr) {
			ptr = p.ptr;
			refCount = ++p.refCount;
			++p.refCount;
		}
	}
	Shared_ptr& operator=(const Shared_ptr&& p) {
		if(p.ptr != ptr) {
			ptr = std::move(p.ptr);
			refCount = std::move(p.refCount);
			p.ptr = nullptr;
		}
	}
	~Shared_ptr() {
		if(--refCount <= 0) {
			std::cout<<"Calling Deleter"<<std::endl;
			deleter(ptr);
		} else {
			std::cout<<"Out of scope "<<std::endl;
		}
	}
	void addDel(std::function<void(T*)> d) {
		deleter = d;
	}
	void del(T* p) {
		std::cout<<"in deleter"<<std::endl;
		delete p;
	}
	T get() {
		return *ptr;
	}
	Shared_ptr& operator=(const T& v) {
		*ptr = v;
	}
private:
	int refCount = 0;
	T* ptr = nullptr;
	std::function<void(T*)> deleter;
};

template <typename T, typename D = std::function<void(T*)>>
class Unique_ptr{
public:	
	Unique_ptr(D del) : ptr(new T), deleter(del) {}
	Unique_ptr(T* p, D del) : ptr(p), deleter(del) {}
	Unique_ptr(Unique_ptr&& p) : ptr(std::move(p.ptr)), deleter(std::move(p.deleter)) 
		{p.ptr = nullptr;}
	Unique_ptr& operator=(const Unique_ptr&& p) {
		if(p.ptr != ptr) {
			ptr = std::move(p.ptr);
			deleter = p.deleter;
			p.ptr = nullptr;
		}
	}
	~Unique_ptr() {
		std::cout<<"Calling Deleter"<<std::endl;
		deleter(ptr);
	}
	void del(T* p) {
		std::cout<<"in Unique deleter"<<std::endl;
		delete p;
	}
	void addDel(D d) {
		deleter = d;
	}
	T get() {
		return *ptr;
	}
	Unique_ptr& operator=(const T& v) {
		*ptr = v;
	}
private:
	T* ptr = nullptr;
	D deleter;
};
