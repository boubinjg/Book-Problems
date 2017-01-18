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
	//this version is a bit annoying, as you have to read in query outside of the loop the first time
	std::cin>>query;
	do{
		if(wordLocs.find(query) != wordLocs.end()) {
			for(auto i : wordLocs[query])
				std::cout<<"Line "<<i<<" "<<lines[i-1]<<std::endl;
		} else {
			std::cout<<"not found"<<std::endl;
		}
	}while(std::cin>>query);
	return 0;
}
