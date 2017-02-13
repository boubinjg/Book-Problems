#include<iostream>
#include<vector>
#include<map>
#include<memory>
#include<fstream>
#include<set>
#include<sstream>
#include<string>
#ifndef QUERY_H
#define QUERY_H
class TextQuery{

public:
	class QueryResult;
	using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream&);
	QueryResult query(const std::string&) const;
private:
	std::shared_ptr<std::vector<std::string>> file;
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};
class TextQuery::QueryResult {
	
friend std::ostream& print(std::ostream&, const QueryResult&);
public:
	QueryResult(std::string s, std::shared_ptr<std::set<line_no>> p,
		    std::shared_ptr<std::vector<std::string>> f):
		    sought(s), lines(p), file(f) {}
private:
	std::string sought;
	std::shared_ptr<std::set<line_no>> lines;
	std::shared_ptr<std::vector<std::string>> file;
};

TextQuery::TextQuery(std::ifstream &is) : file(new std::vector<std::string>)
{
	std::string text;
	while(std::getline(is, text)) {
		file->push_back(text);
		int n = file->size() -1;
		std::istringstream line(text);
		std::string word;
		while(line>>word) {
			auto &lines = wm[word];
			if(!lines)
				lines.reset(new std::set<line_no>);
			lines->insert(n);
		}
	}
}
TextQuery::QueryResult TextQuery::query(const std::string &sought) const
{
	static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
	auto loc = wm.find(sought);
	if(loc == wm.end())
		return QueryResult(sought, nodata, file);
	else
		return QueryResult(sought, loc->second, file);
}
std::ostream &print(std::ostream & os, const TextQuery::QueryResult &qr)
{
	os << qr.sought << " occurs " << qr.lines->size() << " times." << std::endl;
	for(auto num : *qr.lines) {
		os<<"\t(line "<<num + 1 <<") "
	          <<*(qr.file->begin() + num) << std::endl;
	}
	return os;
}
#endif
