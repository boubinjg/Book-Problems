#include<iostream>
#include<vector>
#include<map>
#include<memory>
#include<fstream>
#include<set>
#include<sstream>
#include<string>
//#include"12.19.h"
#include"12.22.h"
#ifndef QUERY_H
#define QUERY_H
class QueryResult;
class TextQuery{

public:
	using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream&);
	QueryResult query(const std::string&) const;
private:
	std::shared_ptr<StrBlob> file;
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};
class QueryResult {
	using line_no = std::vector<std::string>::size_type;
friend std::ostream& print(std::ostream&, const QueryResult&);
public:
	QueryResult(std::string s, std::shared_ptr<std::set<line_no>> p,
		    std::shared_ptr<StrBlob> f):
		    sought(s), lines(p), file(f) {}
private:
	std::string sought;
	std::shared_ptr<std::set<line_no>> lines;
	std::shared_ptr<StrBlob> file;
};

TextQuery::TextQuery(std::ifstream &is) : file(new StrBlob)
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
QueryResult TextQuery::query(const std::string &sought) const
{
	static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
	auto loc = wm.find(sought);
	if(loc == wm.end())
		return QueryResult(sought, nodata, file);
	else
		return QueryResult(sought, loc->second, file);
}
std::ostream &print(std::ostream & os, const QueryResult &qr)
{
	os << qr.sought << " occurs " << qr.lines->size() << " times." << std::endl;
	for(auto num : *qr.lines) {
		ConstStrBlobPtr p(qr.file, num);
		os<<"\t(line "<<num + 1 <<") "
	          << p.deref() << std::endl;
	}
	return os;
}
#endif