#include<map>
#include<string>
int main()
{
	std::map<int, std::string> m;
	m[0] = "asdf";
	m[1.1] = "a";
	char c = 5;
	m[c] = "5";
	return 0;	
}
