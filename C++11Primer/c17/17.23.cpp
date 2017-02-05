#include<regex>
#include<iostream>
int main()
{
	std::string p = "\\d{5}(-\\d{4})?";
	std::regex r(p);
	std::smatch m;
	std::string s;
	while(std::cin>>s) {
		for(std::sregex_iterator it(s.begin(), s.end(), r), endit; it != endit; ++it) {
			std::cout<<it->str()<<std::endl;
		}
	}
	return 0;
}
