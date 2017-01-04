#include<vector>
#include<iostream>
int main() {
	std::vector<int> v = {1,2,3,4,5,6,7,8};
	for(auto &i : v){
		i %2 == 1 ? i*=2 : i;
	}

	for(auto i : v)
		std::cout<<i<<std::endl;
	return 0;
}
