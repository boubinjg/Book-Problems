#include<vector>
int main()
{
	//3 ways to create a vector with 10 42s. I prefer the first way, as it is the shortest
	//and the values are all the same, but any can be used given other situations.
	std::vector<int> i1(10,42);
	std::vector<int> i2{42,42,42,42,42,42,42,42,42,42};
	std::vector<int> i3;
	for(decltype(i3.size()) i = 0; i<10; i++)
		i3.push_back(42);
	return 0;
}
