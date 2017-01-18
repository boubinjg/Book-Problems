#include"12.19.h"
#include<fstream>
#include<iostream>
int main()
{
	StrBlob sb;
	std::ifstream in("12.20.txt");
	std::string s;
	while(in>>s) {
		sb.push_back(s);
	}
	
	StrBlobPtr sbp(sb, 0);
	auto end = sb.end();
	for(auto it = sb.begin(); it != sb.end(); sbp.incr())
		std::cout<<sbp.deref()<<std::endl;
	return 0;
}
