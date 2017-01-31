#include<string>
#include<iostream>
template <unsigned h, unsigned w>
class Screen{
public:
	Screen() = default;
	
	Screen(char c) : contents(w*h, c) {}
	
	char getLoc(unsigned x, unsigned y) {
		return contents[width * y + x];	
	}
private:
	std::string contents;
	std::string::size_type width = w, height = h;
};

