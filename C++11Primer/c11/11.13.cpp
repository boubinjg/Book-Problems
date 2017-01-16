#include<iostream>
#include<string>
#include<vector>
int main()
{
	std::vector<std::pair<std::string,int>> v;
	std::string s;
	int i;
	while(std::cin>>s>>i) {
		v.push_back({s,i});
		v.push_back(std::make_pair(s,i));
		v.push_back(std::pair<std::string, int>(s,i));
	}
	for(auto p : v)
		std::cout<<p.first<<" "<<p.second<<std::endl;
	return 0;
}
