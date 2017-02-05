#include<regex>
#include<iostream>
#include<set>
int main()
{
	std::cout<<"Give me some words"<<std::endl;
	std::string s;
	std::regex r("[[:alpha:]]*[^c]ei[[:alpha:]]*");
	std::smatch m;
	std::set<std::string> correctWords;
	correctWords.insert("neighbor");
	correctWords.insert("weird");
	correctWords.insert("albeit");
	while(std::cin>>s) {
		for(std::sregex_iterator it(s.begin(), s.end(), r), endit; 
		    it != endit; ++it)
		{
			std::string cur = it->str();
			if(correctWords.find(cur) == correctWords.end())
				std::cout<<cur<<std::endl;
		}
	}
	return 0;
}
