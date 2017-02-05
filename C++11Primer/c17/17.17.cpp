#include<regex>
#include<iostream>
#include<set>
int main()
{
	std::cout<<"Give me some words"<<std::endl;
	std::string s;
	std::regex r("[[:alpha:]]*[^c]ei[[:alpha:]]*");
	std::smatch m;
	while(std::cin>>s) {
		for(std::sregex_iterator it(s.begin(), s.end(), r), endit; 
		    it != endit; ++it)
			std::cout<<it->str()<<std::endl;
	}
	return 0;
}
