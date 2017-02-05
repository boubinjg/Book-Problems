#include<tuple>
#include<utility>
#include<vector>
#include<string>
int main()
{
	std::tuple<std::string, std::vector<std::string>, std::pair<std::string, int>>
	{"asdf",{"asdf","gfd"},{"adf", 10}};
	return 0;
}
