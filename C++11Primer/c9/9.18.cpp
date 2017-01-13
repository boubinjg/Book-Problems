#include<iostream>
#include<deque>
#include<string>
int main()
{
	std::deque<std::string> d;
	std::string s;
	while(std::cin>>s) {
		d.push_back(s);
	}

	for(auto st : d)
		std::cout<<st<<std::endl;
	return 0;
}
