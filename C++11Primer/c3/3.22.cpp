#include<vector>
#include<string>
#include<cctype>
#include<iostream>
int main()
{
	std::vector<std::string> text;
	text.push_back("asdfsaf");
	text.push_back("lasfljasdl;jk");
	text.push_back("");

	for(auto it = text.begin(); it!=text.end() && !it->empty(); it++)
		for(auto &c : *it)
			c = std::toupper(c);

	for(auto it = text.cbegin(); it!=text.cend() && !it->empty(); it++)
		std::cout<<*it<<std::endl;
	return 0;
}
