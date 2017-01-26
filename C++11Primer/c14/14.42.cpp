#include<iostream>
#include<functional>
#include<algorithm>
#include<vector>

int main()
{
	std::vector<int> v{1, 2, 3, 4, 1025, 1036, 1055};
	std::greater<int> gr;
	int largecount = 0;
	for(auto i : v)
		if(gr(i, 1024)) {largecount++; }
	std::cout<<largecount<<std::endl;

	std::vector<std::string> s{"pooh", "pooh", "poooh"};
	std::not_equal_to<std::string> neql;
	for(auto i : s)
		if(neql(i, "pooh")) {
			std::cout<<i<<std::endl;
			break;
		}
	std::multiplies<int> mul;
	for(auto i : v) {
		i = mul(i, 2);
		std::cout<<i<<" ";
	}
	std::cout<<std::endl;
}
