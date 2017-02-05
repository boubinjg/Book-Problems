#include<regex>
#include<iostream>
int main()
{
	//this will still work, it simply searches the word for the regex.
	std::cout<<"Give me some words"<<std::endl;
	std::string s;
	std::regex r("[^c]ei");
	std::smatch m;
	while(std::cin>>s) {
		if(std::regex_search(s,m,r)) 
			std::cout<<s<<" is definitely not ok"<<std::endl;
		else
			std::cout<<s<<" is ok"<<std::endl;
	}
	return 0;
}
