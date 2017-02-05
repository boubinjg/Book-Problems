#include<string>
#include<vector>
#include<tuple>
#include<algorithm>
#include"Sales_data.h"
#include<iostream>
#include<utility>
bool compareIsbn(Sales_data d1, Sales_data d2)
{
	return d1.isbn() < d2.isbn();
}
typedef std::tuple<std::vector<Sales_data>::size_type,
		   std::vector<Sales_data>::const_iterator,
		   std::vector<Sales_data>::const_iterator> matches;

typedef std::pair<std::vector<Sales_data>::size_type,
		  std::pair<std::vector<Sales_data>::const_iterator,
		            std::vector<Sales_data>::const_iterator>> pairMatches;

std::vector<pairMatches>
findBook(const std::vector<std::vector<Sales_data>> &files,
	 const std::string &book)
{
	std::vector<pairMatches> ret;
	for(auto it = files.cbegin(); it != files.cend(); ++it)
	{
		auto found = std::equal_range(it->cbegin(), it->cend(),
			 		      book, compareIsbn);
		if(found.first != found.second) {
			auto p = std::make_pair( it - files.cbegin(),
						      std::make_pair(found.first, found.second));
			ret.push_back(p);
		}
	}
	return ret;
}
void reportResults(std::istream &in, std::ostream &os, 
		   const std::vector<std::vector<Sales_data>> &files)
{
	std::string s;
	while(in >> s) {
		auto trans = findBook(files, s);
		if(trans.empty()) {
			std::cout<<s<<"not found in any stores"<<std::endl;
			continue;
		}
		for(const auto &store : trans)
			os<< "store " << std::get<0>(store) << " Sales: " << std::endl;
	}
}
int main()
{
	return 0;
}
