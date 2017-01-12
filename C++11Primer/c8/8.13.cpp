#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<vector>
struct PersonInfo {
	std::string name;
	std::vector<std::string> phones;
};
int main(int argc, char** argv)
{
	std::string line, word;
	std::vector<PersonInfo> people;
	std::ifstream fs(argv[1]);

	while(std::getline(fs, line)) {
		PersonInfo info;
		std::istringstream record(line);
		record >> info.name;
		while(record>>word)
			info.phones.push_back(word);
		people.push_back(info);
	}
	std::cout<<people[0].name<<std::endl;
	return 0;
}
