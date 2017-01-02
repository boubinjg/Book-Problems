#include<iostream>
#include<vector>
int main()
{
	//this is not legal. ivec doesn't have an index 0. To give it one, use push_back
	std::vector<int> ivec;
	ivec[0] = 42;
	return 0;
}
