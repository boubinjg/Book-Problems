#include<iostream>
#include<string>
#include<vector>
class Book 
{
	friend std::ostream& operator<<(std::ostream&, const Book&);
	using page = std::vector<std::string>;
	using pageVec = std::vector<page>;
private:
	pageVec pages;
	std::string ISBN, title, author;
public:
	Book() = default;
	Book(std::string is, std::string ti, std::string au) 
	: ISBN(is), title(ti), author(au) {}
	Book(std::string is, std::string ti, std::string au, pageVec pv) 
	: ISBN(is), title(ti), author(au), pages(pv) {}

};
std::ostream& operator<<(std::ostream& lhs, const Book& rhs)
{
	lhs<<rhs.ISBN<<" "<<rhs.title<<" "<<rhs.author<<std::endl;
}
//should provide overloaded ==, !=, >>, and <<
