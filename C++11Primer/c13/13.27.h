#include<string>
class HasPtr{
public:
	HasPtr(const std::string &s = std::string()) :
		ps(new std::string(s)), i(0), use(new int(0)) {}

	HasPtr(const HasPtr& h) :
		ps(new std::string(*(h.ps))), i(h.i)
	{
		use = h.use;
		use++;
	}
	
	HasPtr& operator=(HasPtr& rhs) {
		if(!(--*use)){
			delete ps;
			delete use;
		}
		use = rhs.use;
		++*use;
		i = rhs.i;
		ps = rhs.ps;
		return *this;
	}
	~HasPtr()
	{
		if(!(--*use)) {
			delete use;
			delete ps;
		}	
	}
private:
	std::string *ps;
	int i;
	int *use;
};
