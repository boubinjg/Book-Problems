#include<iostream>
#include<string>
int main()
{
	std::string s;
	std::cin>>s;
	decltype(s.size()) i = 0;
	while(i < s.size())
	{
		s[i] = 'X';
		i++;
	}
	std::cout<<s<<std::endl;
}
