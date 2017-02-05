#include<regex>
#include<iostream>
int main()
{
	std::string p = "(\\d{5})(\\d{4})?";
	std::regex r(p);
	std::smatch m;
	std::string s;
	std::string fmt = "$1-$2";
	while(std::cin>>s) {
		std::cout<<std::regex_replace(s, r, fmt)<<std::endl;
	}
	return 0;
}
