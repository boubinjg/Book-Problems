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
class QueryResult;
class TextQuery{
public:
	int line;
	TextQuery(std::string infile);
	QueryResult query(std::string);
private:
	std::vector<std::string> lines;
	std::map<std::string, std::set<int>> wordLocs;
};
class QueryResult {
public:
	void print();
private:
	std::string queryWord;
	std::shared_ptr<TextQuery> info;
};
#endif
