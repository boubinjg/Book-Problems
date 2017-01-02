#include<iostream>
#include<string>
#include<cstring>
int main()
{
	//comparison between c++ strings is easier, but not by much
	std::string s = "abc";
	std::string s2 = "abc";
	std::string s3 = "abcd";

	std::cout<<(s==s2)<<" "<<(s==s3)<<std::endl;
	
	const char cs[] = {'a','b','c','\0'};
	const char cs2[] = {'a','b','c','\0'};
	const char cs3[] = {'a','b','c','d','\0'};
	
	std::cout<<std::strcmp(cs,cs2)<<" "<<std::strcmp(cs,cs3)<<std::endl;
}
