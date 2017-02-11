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
	auto cpt = &Screen::cursor;
	Screen s, *pS = &s;	
	s.cursor = 5;
	std::cout<<pS->*cpt<<std::endl;
	return 0;
}
