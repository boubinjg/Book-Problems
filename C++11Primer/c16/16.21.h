#include<iostream>
#include<memory>
class DebugDelete{
public:
	DebugDelete(std::ostream &s = std::cerr) : os(s) {}
	template <typename T> void operator()(T *p) const 
	{os<<"deleting Unique_ptr"<<std::endl; delete p; }
private:
	std::ostream& os;
};
