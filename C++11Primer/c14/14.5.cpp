#include<iostream>
#include<string>
#include<vector>
class Book 
{
	friend std::ostream& operator<<(std::ostream&, const Book&);
	friend std::istream& operator>>(std::istream&, Book&);
	friend bool operator==(Book&, Book&);
	friend bool operator!=(Book&, Book&);
	friend bool operator<(Book& lhs, Book& rhs);
	friend bool operator<=(Book& lhs, Book& rhs);
	friend bool operator>(Book& lhs, Book& rhs);
	friend bool operator>=(Book& lhs, Book& rhs);	

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
	Book& operator=(std::string&);
};
Book& Book::operator=(std::string& s)
{
	ISBN = s;
	return *this;
}
bool operator<(Book& lhs, Book& rhs)
{
	return lhs.ISBN <rhs.ISBN;
}
bool operator<=(Book& lhs, Book& rhs)
{
	return lhs.ISBN <= rhs.ISBN;
}
bool operator>(Book& lhs, Book& rhs)
{
	return rhs < lhs;
}
bool operator>=(Book& lhs, Book& rhs)
{
	return rhs <= lhs;
}

std::ostream& operator<<(std::ostream& lhs, const Book& rhs)
{
	lhs<<rhs.ISBN<<" "<<rhs.title<<" "<<rhs.author<<std::endl;
}
std::istream& operator>>(std::istream& lhs, Book& rhs)
{
	lhs>>rhs.ISBN>>rhs.title>>rhs.author;
	if(!lhs)
		rhs = Book(); 
	return lhs;
}
bool operator==(Book& lhs, Book& rhs)
{
	return lhs.ISBN == rhs.ISBN;
}
bool operator!=(Book& lhs, Book& rhs)
{
	return !(lhs == rhs);
}
//this probably doesnt need arithmetic operators.
//should provide overloaded ==, !=, >>, and <<
