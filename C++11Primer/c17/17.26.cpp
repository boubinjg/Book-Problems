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
		for(std::sregex_iterator it(s.begin(), s.end(), r), endit; 
		    ++it != endit;) {
			std::cout<<std::regex_replace(it->str(), r, fmt)<<std::endl;
		}
	}
	
	return 0;
}
