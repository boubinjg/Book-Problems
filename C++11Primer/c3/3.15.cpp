#include<iostream>
#include<vector>
#include<string>
int main()
{
	std::string s;
	std::vector<std::string> v;
	while(std::cin>>s)
		v.push_back(s);
	return 0;
}
