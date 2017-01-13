#include<iostream>
#include<fstream>
#include<string>
bool findAscend(std::string s)
{
	return s.find_first_of("bdfghjlpqty") != std::string::npos;
}
int main()
{
	std::ifstream f("9.49.txt");
	std::string line, ret;
	while(f>>line)
	{
		if(!findAscend(line) && line.length() > ret.length())
			ret = line;
	}
	std::cout<<ret<<std::endl;
	return 0;
}
