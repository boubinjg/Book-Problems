#include<map>
#include<string>
#include<vector>
int main()
{
	std::map<std::string, std::vector<int>> m;
	std::map<std::string, std::vector<int>>::iterator pos = m.find("0");
	return 0;
}
