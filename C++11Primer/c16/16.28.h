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
		
	}
private:
	int refCount = 0;
	T* ptr = nullptr;
	std::function<void(T*)> deleter;
};
