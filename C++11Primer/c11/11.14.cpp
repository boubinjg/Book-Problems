#include<map>
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
#include<iterator>
using FMap = std::map<std::string, std::vector<std::pair<std::string,std::string>>>;
void add(FMap& familyMap)
{
	std::vector<std::pair<std::string,std::string>> kids;
	std::string name, cname, birthday;
	std::cin>>name;
	while(std::cin>>cname>>birthday)
		kids.push_back({cname,birthday});
	familyMap[name] = kids;
}
int main()
{
	FMap familyMap;
	add(familyMap);
	
	for(auto i : familyMap){
		std::cout<<i.first<<std::endl;
		for(auto k : i.second)
			std::cout<<k.first<<" "<<k.second<<std::endl;
	}
	return 0;
}
