#include<string>
class HasPtr{
public:
	HasPtr(const std::string &s = std::string()) :
		ps(new std::string(s)), i(0) {}

	HasPtr(const HasPtr& h) :
		ps(new std::string(*(h.ps))), i(h.i) {}
	
	HasPtr& operator=(HasPtr& rhs) {
		std::string tmp = *(rhs.ps);
		i = rhs.i;
		ps = new std::string(tmp);
		return *this;
	}
	~HasPtr()
	{
		delete ps;	
	}
private:
	std::string *ps;
	int i;
};
