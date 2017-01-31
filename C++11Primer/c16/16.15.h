#include<string>
#include<iostream>
template <unsigned h, unsigned w>
class Screen{
public:
	
	Screen() = default;
	
	Screen(char c) : 
	contents(w*h, c) {}
	
	char getLoc(unsigned x, unsigned y) {
		return contents[width * y + x];	
	}

	friend std::ostream& operator<<(std::ostream& os, const Screen<h,w>& s) 
	{
		os<<s.contents<<" ";
		return os;
	}

	friend std::ostream& operator>>(std::istream& is, Screen<h,w>& s)
	{
		char c;
		is>>c;
		s.contents = std::string(s.width*s.height, c);
	}

private:
	std::string contents;
	std::string::size_type width = w, height = h;
};
