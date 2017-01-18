#include<iostream>
#include<string>
int main()
{
	std::string s1 = "abcd";
	std::string s2 = "efgh";
	char* cat = new char[s1.length()+s2.length() + 1];

	for(size_t i = 0; i<s1.length(); i++)
		cat[i] = s1[i];
	for(size_t i = s1.length(); i<s1.size()+s2.length(); i++)
		cat[i] = s2[i-s1.length()];
	cat[s1.size() + s2.size()] = '\0';

	std::cout<<cat<<std::endl;
	std::cout<<s1+s2<<std::endl;
}
