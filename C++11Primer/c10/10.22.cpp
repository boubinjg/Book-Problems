#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<functional>
bool isShorter(const std::string& s1, std::string::size_type sz)
{
	return s1.size() >= sz;
}
void biggies (std::vector<std::string> v, std::string::size_type sz)
{
	std::sort(v.begin(), v.end());
	auto un = std::unique(v.begin(), v.end());
	v.erase(un, v.end());
	std::stable_sort(v.begin(),v.end(), 
			 [](const std::string s1, const std::string s2){return s1.size()<s2.size();});
	auto b = bind(isShorter, std::placeholders::_1, sz);
	auto count = std::count_if(v.begin(), v.end(), b);

	std::cout<<count<<std::endl;

	/*
	std::for_each(fi, v.end(),
	             [](const std::string s){std::cout<<s<<std::endl;});
	*/
}
int main()
{
	std::vector<std::string> v{"a","abcdef","aef","asdfasdf","fffff","ffff", "fffff"};
	biggies(v,5);
}
