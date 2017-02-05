#include<iostream>
#include<vector>
#include<map>
#include<memory>
#include<fstream>
#include<set>
#include<sstream>
#include<string>
#include<tuple>
#ifndef QUERY_H
#define QUERY_H
class QueryResult;
class TextQuery{

public:
	using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream&);
	std::tuple<std::string, 
		   std::shared_ptr<std::set<line_no>>, 
		   std::shared_ptr<std::vector<std::string>>>
		   query(const std::string&) const;
private:
	std::shared_ptr<std::vector<std::string>> file;
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};
#endif
//I believe the QueryResult class usage is better. Not only is the typle syntax verbose with the
//arguments it must have, but it provides less functionality than the QueryResult class.
