#include<iostream>
#include<vector>
#include<string>
int main()
{
	std::vector<std::string> s{"1","2","3","4","5"};
	int sum = 0;
	for(auto str : s) {
		sum += std::stoi(str);
	}
	std::cout<<sum<<std::endl;

	std::vector<std::string> sd{"1.1","2.2","3.3","4.4","5.5"};
	double dsum = 0;
	for(auto str : sd) {
		dsum += std::stod(str);
	}
	std::cout<<dsum<<std::endl;


	return 0;
}
