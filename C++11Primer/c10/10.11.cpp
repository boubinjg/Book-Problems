#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
bool isShorter(std::string s1, std::string s2) 
{return s1.size() < s2.size();}
int main()
{
	std::vector<std::string> i{"a","c","abc","ay","zz","abcdef","a", "ff","ff","g"};
	
	std::sort(i.begin(), i.end());
	auto it = std::unique(i.begin(), i.end());
	i.erase(it, i.end());
	
	std::stable_sort(i.begin(), i.end(), isShorter);
	for(auto v : i)
		std::cout<<v<<" ";
	std::cout<<std::endl;

	return 0;
}
