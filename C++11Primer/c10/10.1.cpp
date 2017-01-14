#include<iostream>
#include<vector>
#include<algorithm>
int main()
{
	std::vector<int> v;
	int i;
	std::cout<<"enter the values in the vector"<<std::endl;
	while(std::cin>>i) {
		v.push_back(i);
	}
	std::cin.clear();
	
	int find; 
	std::cout<<"enter the value to count"<<std::endl;
	std::cin>>find;
	std::cout<<std::count(v.begin(), v.end(), find)<<std::endl;	
	return 0;
}
