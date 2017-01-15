#include<fstream>
#include<iostream>
#include<iterator>
#include<vector>
#include<algorithm>
int main()
{
	std::ifstream in("10.33.txt");
	std::ofstream out1("10.33.1.o"), out2("10.33.2.o");
	
	std::istream_iterator<int> ini(in), eof;
	std::ostream_iterator<int> o1(out1, " "), o2(out2, "\n");

	for(;ini != eof; ++ini) {
		if(*ini%2)
			o1 = *ini;
		else
			o2 = *ini;
	}
	return 0;
}
