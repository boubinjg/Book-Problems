#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iterator>
int main()
{
	std::vector<std::string> v;
	std::fstream in("10.29.txt");
	std::istream_iterator<std::string> it(in), eof;
	std::copy(it, eof, std::back_inserter(v));
	
	for(auto s : v)
		std::cout<<s<<std::endl;
	
	return 0;
}
