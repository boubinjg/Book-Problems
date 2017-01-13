#include<iostream>
#include<list>
#include<string>
int main()
{
	//changed deque to list
	std::list<std::string> l;
	std::string s;
	while(std::cin>>s) {
		l.push_back(s);
	}

	for(auto st : l)
		std::cout<<st<<std::endl;
	return 0;
}
