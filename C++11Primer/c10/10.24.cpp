#include<vector>
#include<string>
#include<functional>
#include<algorithm>
#include<iostream>
bool check_size(const std::string &s, std::string::size_type sz) 
{return s.size() <= sz;}
int main()
{
	std::vector<int> v{1,2,3,4,5,8};
	std::string s = "asdfasd";
	auto i = std::find_if(v.begin(), v.end(), bind(check_size, s, std::placeholders::_1));
	std::cout<<*i<<std::endl;
	return 0;
}
