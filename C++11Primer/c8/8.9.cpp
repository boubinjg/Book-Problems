#include<iostream>
#include<sstream>
std::istringstream& read(std::istringstream& io)
{
	std::string s;
	while(io>>s) {
		std::cout<<s<<std::endl;
	}
	io.clear();
	return io;
}
int main()
{
	std::istringstream s("abcd efgh ijkl mnop");
	read(s);
	return 0;
}
