#include<iostream>
#include<list>
#include<vector>
#include<string>
int main()
{
	std::list<char*> sl{"asdf", "fdsa","sdfg"};
	std::vector<std::string> sv;
	sv.assign(sl.begin(), sl.end());

	for(auto s : sv)
		std::cout<<s<<std::endl;
	return 0;
}
