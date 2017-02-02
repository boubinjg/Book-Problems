#include<vector>
#include<memory>
#include"16.28.h"
template <typename T> class BlobPtr;
template <typename T> class Blob;
template <typename T> 
	bool operator ==(const Blob<T>&, const Blob<T>);

template <typename T> class Blob {
	friend class BlobPtr<T>;
	friend bool operator==<T>(const Blob<T>&, const Blob<T>&);
public:
	typedef T value_type;
	typedef typename std::vector<T>::size_type size_type;
	
	Blob();
	Blob(std::initializer_list<T> il);
	template<typename It> Blob(It&, It&);
	size_type size() const {return data.get().size();}
	bool empty() const {return data.get().empty();}
	void push_back(const T &t) {data.get().push_back(t);}
	void push_back(T &&t) {data.get().push_back(std::move(t));}
	void pop_back();
	T& back();
	T& operator[](size_type i);
private:
	Shared_ptr<std::vector<T>> data;
	void check(size_type i, const std::string &msg) const;
};

template <typename T> class BlobPtr{
public:
	BlobPtr(): curr(0) {}
	BlobPtr(Blob<T> &a, size_t sz = 0):
		wptr(a.daa), curr(sz) {}
	T& operator*() const {
		auto p = check(curr, "deref past end");
		return (*p)[curr];
	}
	BlobPtr& operator++();
	BlobPtr& operator--();
private:
	std::shared_ptr<std::vector<T>> check(std::size_t, const std::string&) const;
	std::weak_ptr<std::vector<T>> wptr;
	std::size_t curr;
};

template<typename T>
template<typename It>
Blob<T>::Blob(It& b, It& e)
{
	data = std::make_shared<std::vector<T>>(b, e);
}

template<typename T>
void Blob<T>::check(size_type i, const std::string &msg) const
{
	if(i>=data->size())
		throw std::out_of_range(msg);
}
template <typename T>
T& Blob<T>::back()
{
	check(0, "back on empty Blob");
	return data->back();
}
template <typename T>
T& Blob<T>::operator[](size_type i)
{
	check(i, "subscript out of range");
	return (*data)[i];
}
template <typename T> 
void Blob<T>::pop_back()
{
	check(0, "pop_back on empty Blob");
	data->pop_back();
}
template <typename T>
Blob<T>::Blob(std::initializer_list<T> li) :
	data(std::make_shared<std::vector<T>>(li)) {}
