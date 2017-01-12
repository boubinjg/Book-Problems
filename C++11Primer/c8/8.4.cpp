#include<fstream>
#include<iostream>
#include<string>
#include<vector>
void read(std::string fname)
{
	std::ifstream fs(fname);
	std::string s;
	std::vector<std::string> svec;
	while(std::getline(fs, s)) {
		svec.push_back(s);
	}
	for(auto i : svec)
		std::cout<<i<<std::endl;
}
int main()
{
	read("8.4.txt");
	return 0;
}
