#include<sstream>
#include<vector>
#include<iostream>
#include<string>
int main()
{
	std::string line, word;
	std::vector<std::string> words;
	std::istringstream record;
	while(getline(std::cin, line)) {
		record.clear();
		record.str(line);
		while(record>>word)
			words.push_back(word);
	}
	for(auto s : words)
		std::cout<<s<<std::endl;
	return 0;
}
