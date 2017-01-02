#include<iostream>
#include<string>
int main()
{
	std::string s1, s2;
	std::cin>>s1>>s2;
	if(s1==s2)
		std::cout<<"The Strings are Equal"<<std::endl;
	else if(s1>s2)
		std::cout<<s1<<" is greater than "<<s2<<std::endl;
	else
		std::cout<<s2<<" is greater than "<<s1<<std::endl;

	if(s1.size() == s2.size())
		std::cout<<"Same Size"<<std::endl;
	else if(s1.size() > s2.size())
		std::cout<<s1<<" is longer than than "<<s2<<std::endl;
	else
		std::cout<<s2<<" is longer than "<<s1<<std::endl;
}
