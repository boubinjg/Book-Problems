#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
int main()
{
	using std::placeholders::_1;
	std::vector<int> v{1, 3, 5, 7, 9, 11, 13, 4};
	std::modulus<int> mod;
	int given = 100;
	for(auto i : v)
		if(!(mod(given,i))) {
			std::cout<<"divisible by "<<i<<std::endl;
			break;
		}
	return 0;
}
