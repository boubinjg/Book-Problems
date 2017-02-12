#include<string>
#include<algorithm>
#include<functional>
#include<iostream>
#include<vector>
int main()
{
	std::string s;
	auto f = std::mem_fn(&std::string::empty);
	std::vector<std::string> v{"","asdf","","asdffds","f",""};
	int i = std::count_if(v.begin(), v.end(), f);
	std::cout<<i<<std::endl;
	return 0;
}
