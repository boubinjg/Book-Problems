#include<fstream>
#include<iterator>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
int main()
{
	std::fstream infile("11.3.txt");
	std::istream_iterator<std::string> in(infile), eof;
	std::map<std::string, int> map;
	std::set<std::string> s{"example.","Example","example"};
	
	while(in != eof) {
		if(s.find(*in) == s.end()) {
			auto ret = map.insert({*in, 1});
			if(!ret.second)
				++ret.first->second;
		}
		++in;
	}
	
	for(auto p : map)
		std::cout<<p.first<<" "<<p.second<<std::endl;
	
	return 0;
}
