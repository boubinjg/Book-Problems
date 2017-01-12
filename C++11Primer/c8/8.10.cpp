#include<fstream>
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
void read(std::string fname)
{
	std::ifstream fs(fname);
	std::string s, word;
	std::vector<std::string> svec;
	while(std::getline(fs, s)) {
		std::istringstream iss(s);
		while(iss>>word)
			svec.push_back(word);
	}
	for(auto i : svec)
		std::cout<<i<<std::endl;
}
int main()
{
	read("8.4.txt");
	return 0;
}
