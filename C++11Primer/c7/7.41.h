#ifndef SCREEN_H
#define SCREEN_H
#include<string>
class Screen{
public:
	using pos = std::string::size_type;
	Screen(pos ht, pos wd, char c) 
	: height(ht), width(wd), contents(ht*wd, c) {}
	
	Screen() : Screen(0,0,' ') {}
	Screen(pos ht, pos wd) : Screen(ht, wd, ' ') {}
	
	char get() const {return contents[cursor];}
	inline char get(pos ht, pos wd) const;
	Screen &move(pos r, pos c);
	Screen &set(char);
	Screen &set(pos, pos, char);
	Screen &display(std::ostream &os) {do_display(os); return *this;}
	const Screen &display(std::ostream &os) const {do_display(os); return *this;}
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
	void do_display(std::ostream &os) const {os<<contents;}
};
Screen &Screen::move(pos r, pos c)
{
	pos row = r * width;
	cursor = row + c;
	return *this;
}
inline
char Screen::get(pos r, pos c) const
{
	pos row = r*width;
	return contents[row+c];
}
inline Screen &Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}
inline Screen &Screen::set(pos r, pos col, char c)
{
	contents[r*width + col] = c;
	return *this;
}
#endif
