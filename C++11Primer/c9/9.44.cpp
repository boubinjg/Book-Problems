#include<iostream>
#include<string>
std::string replaceAll(std::string s, std::string oldVal, std::string newVal)
{
	auto it = s.begin();
	while(it != s.end()) {
		if(std::string(it, it+oldVal.size()) == oldVal) {
			s.replace(it, it+oldVal.size(), newVal);
			it += newVal.size();
		}
		else
			it++;
	}
	return s;
}
int main()
{
	std::cout<<replaceAll("asdfhhhhhhasdfhhhhasdf", "asdf", "XXX")<<std::endl;
	return 0;
}
