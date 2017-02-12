#include<iostream>
#include<algorithm>
#include<string>
int main()
{
	std::string s = "abcde4fg123";
	auto it = std::stable_partition(s.begin(), s.end(), [](char& c){return !std::isdigit(c);});
	std::rotate(s.begin() + 2,it, s.end());
	std::cout<<s<<std::endl;
}
