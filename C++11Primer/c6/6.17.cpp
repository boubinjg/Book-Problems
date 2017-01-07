#include<iostream>
#include<string>
#include<cctype>
//anyCaps takes a const std::string& because it does not modify the argument, and therefore can accept const
//allCaps does modify the argument, so const variables are not appropriate
bool anyCaps(const std::string& s)
{
	for(auto c : s){
		if(c == std::toupper(c))
			return true;
	}
	return false;
}
void allCaps(std::string& s)
{
	for(auto &c : s){
		c = std::toupper(c);	
	}
}
int main()
{
	std::string s = "abcd";
	allCaps(s);
	std::cout<<anyCaps("abcd")<<" "<<anyCaps("Abcd")<<" "<<s<<std::endl;
	return 0;
}
