#include<vector>
#include<string>
#include<memory>
#include<stdexcept>
#include<iostream>
class ConstStrBlobPtr;
class StrBlob {
public:
	friend class ConstStrBlobPtr;
	ConstStrBlobPtr begin() const;
	ConstStrBlobPtr end() const;

	typedef std::vector<std::string>::size_type size_type;
	StrBlob();
	StrBlob(std::initializer_list<std::string> il);
	StrBlob& operator=(StrBlob&);
	StrBlob(StrBlob&);

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

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}
StrBlob::StrBlob(std::initializer_list<std::string> li) :
		data(std::make_shared<std::vector<std::string>>(li)) {}

StrBlob& StrBlob::operator=(StrBlob& rhs)
{
	data = std::make_shared<std::vector<std::string>>(*(rhs.data));
	return *this;
}
StrBlob::StrBlob(StrBlob& rhs)
{
	data = std::make_shared<std::vector<std::string>>(*(rhs.data));
}
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
