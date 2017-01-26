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
	std::istream_iterator<std::string> inIt(in), npass(in), eof;
	std::ostream_iterator<std::string> outIt(std::cout, " ");
	int sub10 = std::count_if(inIt, eof, sizeTest(9)); 
	
	std::ifstream in2("14.38.txt");
	std::istream_iterator<std::string> inIt2(in2);
	int total = std::count_if(inIt2, eof, sizeTest(-1));
	std::cout<<sub10<<" "<<total-sub10<<std::endl;
	return 0;
}
