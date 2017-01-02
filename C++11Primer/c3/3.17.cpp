#include<iostream>
#include<vector>
#include<string>
#include<cctype>
int main()
{
	std::string s;
	std::vector<std::string> v;
	while(std::cin>>s)
		v.push_back(s);
	for(auto &s : v)
	{
		for(auto &c : s)
			c = std::toupper(c);
	}
	std::cout<<std::endl;
	for(auto s : v)
		std::cout<<s<<std::endl;
	return 0;
}
