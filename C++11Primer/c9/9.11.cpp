#include<vector>
int main()
{
	std::vector<int> one; //empty
	std::vector<int> two(2); //2
	std::vector<int> three(one); //empty
	std::vector<int> four{4}; //4
	std::vector<int> five(5,5); //5 5 5 5 5
	std::vector<int> six(two.begin(), two.end()); //2
	return 0;
}
