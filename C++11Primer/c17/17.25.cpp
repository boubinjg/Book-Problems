#include<regex>
#include<string>
#include<iostream>
int main()
{
	using namespace std::regex_constants;
	std::string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
	std::regex r(phone);
	std::smatch m;
	std::string s, fmt = "$2.$5.$7";
	
	while(getline(std::cin, s, '\n')) {
		std::cout<<std::regex_replace(s,r,fmt, 
		           match_continuous | format_no_copy)<<std::endl;
	}
	
	return 0;
}
