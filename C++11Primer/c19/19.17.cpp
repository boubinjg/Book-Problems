#include<iostream>
#include<string>
class Screen {
public:	
	typedef std::string::size_type pos;
	char get_cursor() const { return contents[cursor]; }
	char get() const {return 'a';}
	char get (pos ht, pos wd) const {return 'b';}
	void setContents(std::string s) {contents = s;}
	
	std::string contents;
	pos cursor;
	pos height, width;
};
int main()
{
	auto pgc = &Screen::get_cursor;
	
	char (Screen::*pg)() const;
	pg = &Screen::get;
	
	char (Screen::*pga)(Screen::pos, Screen::pos) const;
	pga = &Screen::get;
	
	auto pc = &Screen::setContents;
	return 0;
}
