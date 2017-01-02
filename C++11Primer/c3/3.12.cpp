#include<vector>
#include<string>
int main()
{
	//legal, creates an empty vector of vectors of ints
	std::vector<std::vector<int>> ivec;
	//illegal, cant initialize vector with other vector of incorrect type
	//std::vector<string> svec = ivec;
	//legal, creates a string vector containing 10 "null"s
	std::vector<std::string> svec(10, "null");
	return 0;
}
