#include<iostream>
#include<string>
#include<vector>
int main()
{
	std::vector<std::string> s;
	s.push_back("hello");
	s.push_back("world");
	s.push_back("asdf");
	s.push_back("");
	auto iter = s.begin();

	//legal
	*iter++;
	//illegal
	//(*iter)++;
	//illegal
	//*iter.empty();
	//legal
	iter->empty();
	//illegal
	//++*iter;
	//legal
	iter++->empty();
}
