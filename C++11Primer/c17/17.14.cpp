#include<regex>
#include<string>
#include<iostream>
int main()
{
	std::regex r("[[:alpha:]]*");
	std::smatch m;
	std::string s("asdf");
	if(regex_match(s, m, r)) {
		std::cout<<m.str()<<std::endl;
	}
	smatch instead of cmatch
	if(regex_match("asdf", m, r)) {
		std::cout<<m.str()<<std::endl;
	}
	//mismatched [], runtime error
	std::regex r2("[[:alpha:]");
	
	return 0;	
}
