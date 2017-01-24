#include<iostream>
#include<string>
class PrintString{
public:
	PrintString(std::istream &i = std::cin, std::ostream &o = std::cout, char c = ' ')
		:is(i), os(o), sep(c) {}
	std::string operator()() 
	{
		std::string ret;
		std::getline(is, ret);
		if(is)
			return ret;
		return "";
	}
private:
	std::istream &is;
	std::ostream &os;
	char sep;
};
int main()
{
	PrintString p;
	std::string s =  p();
	std::cout<<s<<std::endl;
	return 0;
}
