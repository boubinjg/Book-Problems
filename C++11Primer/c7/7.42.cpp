#include<iostream>
#include<string>
#include<vector>
class Book 
{
	using page = std::vector<std::string>;
	using pageVec = std::vector<page>;
private:
	pageVec pages;
	std::string ISBN, title, author;
public:
	Book(std::string is, std::string ti, std::string au, pageVec pv) 
	: ISBN(is), title(ti), author(au), pages(pv) {}
	Book() : Book("","","",{}) {}
	Book(std::string is, std::string ti, std::string au) 
	: Book(is, ti, au, {}) {}
};
