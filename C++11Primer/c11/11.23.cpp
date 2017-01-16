#include<map>
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
#include<iterator>
using FMap = std::multimap<std::string, std::vector<std::string>>;
void add(FMap& familyMap)
{
	std::vector<std::string> kids;
	std::string name, cname;
	std::cin>>name;
	std::istream_iterator<std::string> in(std::cin), eof;
	std::copy(in, eof, std::back_inserter(kids));
	familyMap.insert({name, kids});
}
int main()
{
	FMap familyMap;
	add(familyMap);
	
	for(auto i : familyMap){
		std::cout<<i.first<<std::endl;
		for(auto k : i.second)
			std::cout<<k<<std::endl;
	}
	return 0;
}
