#include<vector>
#include<map>
#include<string>
int main()
{
	std::map<std::string, std::vector<int>> m;
	std::pair<std::map<std::string,std::vector<int>>::iterator, bool> p = m.insert({"",{}});
	return 0;
}
