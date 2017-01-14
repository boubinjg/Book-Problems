#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
bool isFive(std::string s) {return s.size() < 5; }
int main()
{
	std::vector<std::string> i{"a","cfdsa","abc","ay","zz","abcdef","a", "ffasdfa","aasasff","gfdfdfdf"};
	
	auto it = std::partition(i.begin(), i.end(), isFive);
	
	for(; it!=i.end(); it++)
		std::cout<<*it<<std::endl;
	
	return 0;
}
