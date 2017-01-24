#include<vector>
#include<string>
#include<memory>
#include<stdexcept>
#include<iostream>
class ConstStrBlobPtr;
class StrBlob {
public:
	friend class ConstStrBlobPtr;
	friend bool operator==(StrBlob&, StrBlob&);
	friend bool operator!=(StrBlob&, StrBlob&);
	friend bool operator<(const StrBlob&, const StrBlob&);
	friend bool operator>(const StrBlob&, const StrBlob&);
	friend bool operator<=(const StrBlob&, const StrBlob&);
	friend bool operator>=(const StrBlob&, const StrBlob&);
	
	ConstStrBlobPtr begin() const;
	ConstStrBlobPtr end() const;

	typedef std::vector<std::string>::size_type size_type;
	StrBlob();
	StrBlob(std::initializer_list<std::string> il);
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	
	void push_back(const std::string &t) {data->push_back(t);}
	void pop_back();
	std::string& front();
	const std::string& front() const;
	std::string& back();
	const std::string &back() const;
private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(size_type i, const std::string &msg) const;
};

class ConstStrBlobPtr{

	friend class StrBlob;
	friend bool operator==(ConstStrBlobPtr&, ConstStrBlobPtr&);
	friend bool operator<(ConstStrBlobPtr&, ConstStrBlobPtr&);
	friend bool operator<=(ConstStrBlobPtr&, ConstStrBlobPtr&);
	friend bool operator>(ConstStrBlobPtr&, ConstStrBlobPtr&);
	friend bool operator>=(ConstStrBlobPtr&, ConstStrBlobPtr&);

public:
	
	ConstStrBlobPtr(): curr(0){}
	ConstStrBlobPtr(std::shared_ptr<StrBlob> a, size_t sz = 0) :
		wptr(a->data), curr(sz) {}
	std::string& deref() const;
	ConstStrBlobPtr& incr();	
	bool operator!=(const ConstStrBlobPtr& p) {return p.curr != curr;}
private:
	std::shared_ptr<std::vector<std::string>> 
	check(std::size_t, const std::string&) const;

	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
};
bool operator<(ConstStrBlobPtr& lhs, ConstStrBlobPtr& rhs)
{
	return lhs.curr < rhs.curr;
}
bool operator<=(ConstStrBlobPtr& lhs, ConstStrBlobPtr& rhs)
{
	return lhs.curr <= rhs.curr;
}
bool operator>(ConstStrBlobPtr& lhs, ConstStrBlobPtr& rhs)
{
	return rhs < lhs;
}
bool operator>=(ConstStrBlobPtr& lhs, ConstStrBlobPtr& rhs)
{
	return rhs <= rhs;
}

bool operator<(const StrBlob& lhs, const StrBlob& rhs)
{
	return *lhs.data < *rhs.data;
}
bool operator>(const StrBlob& lhs, const StrBlob& rhs)
{
	return rhs < lhs;
}
bool operator<=(const StrBlob& lhs, const StrBlob& rhs)
{
	return *lhs.data <= *rhs.data;
}
bool operator>=(const StrBlob& lhs, const StrBlob& rhs)
{
	return *rhs.data <= *lhs.data;
}	
bool operator==(ConstStrBlobPtr& lhs, ConstStrBlobPtr& rhs)
{
	return !(lhs!=rhs);
}
bool operator==(StrBlob& lhs, StrBlob& rhs)
{
	return (*lhs.data == *rhs.data);
}
bool operator!=(StrBlob& lhs, StrBlob& rhs)
{
	return !(lhs == rhs);
}
std::shared_ptr<std::vector<std::string>>
ConstStrBlobPtr::check(std::size_t i, const std::string &msg) const
{
	auto ret = wptr.lock();
	if(!ret)
		throw "unbound";
	if(i >= ret->size())
		throw "out of range";
	return ret;
}
std::string& ConstStrBlobPtr::deref() const
{
	auto p = check(curr, "deref");
	return (*p)[curr];
}
ConstStrBlobPtr& ConstStrBlobPtr::incr()
{
	check(curr, "inc");
	++curr;
	return *this;
}

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}
StrBlob::StrBlob(std::initializer_list<std::string> li) :
		data(std::make_shared<std::vector<std::string>>(li)) {}

void StrBlob::check(size_type i, const std::string &msg) const
{
	if(i >= data->size())
		throw std::out_of_range(msg);
}
std::string& StrBlob::front()
{
	check(0, "front on empty StrBlob");
	return data->front();
}
std::string& StrBlob::back()
{
	check(0, "back on empty StrBlob");
	return data->back();
}
const std::string &StrBlob::back() const
{
	check(0, "back on empty StrBlob");
	return data->back();
}
const std::string &StrBlob::front() const
{
	check(0, "front on empty StrBlob");
	return data->front();
}
void StrBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}
