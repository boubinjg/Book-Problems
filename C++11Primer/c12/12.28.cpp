#include<vector>
#include<map>
#include<string>
#include<set>
#include<fstream>
#include<sstream>
#include<iostream>
int main()
{
	std::ifstream in("12.27.txt");
	std::map<std::string, std::set<int>> wordLocs;
	std::vector<std::string> lines;

	std::string line;
	int linen = 1;
	while(std::getline(in, line)) {
		std::string words;
		lines.push_back(line);
		std::istringstream iss(line);
		while(iss>>line)
			wordLocs[line].insert(linen);
		linen++;
	}

	std::string query;
	while(std::cin>>query) {
		if(wordLocs.find(query) != wordLocs.end()) {
			for(auto i : wordLocs[query])
				std::cout<<lines[i-1]<<std::endl;
		} else {
			std::cout<<"not found"<<std::endl;
		}
	}
	return 0;
}
