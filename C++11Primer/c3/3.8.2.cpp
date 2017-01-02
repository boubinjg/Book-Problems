#include<iostream>
#include<string>
int main()
{
	std::string s;
	std::cin>>s;
	for(decltype(s.size()) i = 0; i<s.size(); i++)
	{
		s[i] = 'X';
	}
	std::cout<<s<<std::endl;
}
