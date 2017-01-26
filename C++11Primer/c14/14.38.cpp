#include<iostream>
#include<string>
#include<iterator>
#include<fstream>
#include<algorithm>
class sizeTest{
public:
	sizeTest(int sz) : size(sz) {}  
	bool operator()(const std::string s) const { return s.size() <= size; }
private:
	int size;
};
int main()
{
	std::ifstream in("14.38.txt");
	std::istream_iterator<std::string> inIt(in), eof;
	std::ostream_iterator<std::string> outIt(std::cout, " ");
	int i = std::count_if(inIt, eof, sizeTest(10)); 
	
	std::cout<<i<<std::endl;
	return 0;
}
