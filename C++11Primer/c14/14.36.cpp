#include<iostream>
#include<string>
#include<vector>
class PrintString{
public:
	PrintString(std::istream &i = std::cin, std::ostream &o = std::cout, char c = ' ')
		:is(i), os(o), sep(c) {}
	void operator()() 
	{
		std::string ret;
		while(std::getline(is, ret))
			v.push_back(ret);

	}
private:
	std::istream &is;
	std::ostream &os;
	char sep;
	std::vector<std::string> v;
};
int main()
{
	PrintString p;
	p();
	return 0;
}
