#include<iostream>
#include<map>
#include<string>
#include<fstream>
#include<sstream>
#include<exception>
#include<vector>
#include<random>
static std::default_random_engine e;
const std::string &
transform(const std::string &s, const std::map<std::string, std::vector<std::string>> &m)
{
	auto map_it = m.find(s);
	if(map_it != m.cend()) {
		std::uniform_int_distribution<unsigned> d(0,map_it->second.size()-1);
		return map_it->second[d(e)];
	} else
		return s;
}
std::map<std::string, std::vector<std::string>> buildMap(std::ifstream &map_file)
{
	std::map<std::string, std::vector<std::string>> trans_map;
	std::string key, value;
	while(map_file>>key && getline(map_file, value)) {
		if(value.size() > 1)
			trans_map[key].push_back(value.substr(1));
		else
			throw "no rule for " + key;
	}
	return trans_map;
}
void word_transform(std::ifstream& map_file, std::ifstream& input)
{
	auto trans_map = buildMap(map_file);
	std::string text;
	while(getline(input, text)) {
		std::istringstream stream(text);
		std::string word;
		bool firstword = true;
		while(stream >> word) {
			if(firstword)
				firstword=false;
			else
				std::cout<<" ";
			std::cout<<transform(word,trans_map);
		}
		std::cout<<std::endl;
	}
}
int main()
{
	std::ifstream in("17.33.in"), m("17.33.map");
	word_transform(m, in);
	return 0;
}
