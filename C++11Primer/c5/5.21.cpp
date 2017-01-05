#include<iostream>
#include<string>
#include<cctype>
int main()
{
	std::string buf, last;
	while(std::cin>>buf && !buf.empty()) {
		if(buf != last || buf[0] != std::toupper(buf[0]))
		{
			last = buf;
			continue;
		}
		std::cout<<"Found: "<<buf<<std::endl;
		last = buf;
	}
	return 0;
}
