#include<iostream>
#include<string>
class Screen {
public:	
	typedef std::string::size_type pos;
	char get_cursor() const { return contents[cursor]; }
	char get() const;
	char get (pos ht, pos wd) const;
	void setContents(std::string s) {contents = s;}
	
	std::string contents;
	pos cursor;
	pos height, width;
};
int main()
{
	//not legal, doesnt point to the correct function
	auto pmf = &Screen::get_cursor;
	pmf = &Screen::get;
	return 0;
}
