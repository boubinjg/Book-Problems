#include<fstream>
#include<iterator>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
int main()
{
	std::fstream infile("11.3.txt");
	std::istream_iterator<std::string> in(infile), eof;
	
	std::map<std::string, int> map;
	
	while(in != eof) 
		++map[*in++];
	
	for(auto p : map)
		std::cout<<p.first<<" "<<p.second<<std::endl;
	
	return 0;
}
