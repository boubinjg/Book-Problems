#include<set>
#include<string>
bool compareIsbn(std::string s1, std::string s2) 
{return s1>s2;}
int main()
{
	std::multiset<std::string, bool(*)(std::string, std::string)> s(compareIsbn);
	return 0;
}
