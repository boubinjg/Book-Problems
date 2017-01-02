#include<iostream>
#include<string>
#include<vector>
int main()
{
	//empty int vector
	std::vector<int> v1;
	//int vector with 10 ints with default values
	std::vector<int> v2(10);
	//int vector with 10 ints containing the value 42
	std::vector<int> v3(10, 42);
	//int vector containing the value 10
	std::vector<int> v4{10};
	//int vector containing 10 and 42
	std::vector<int> v5{10,42};
	//string vector with 10 empty strings
	std::vector<std::string> v6{10};
	//string vector with 10 copies of hi
	std::vector<std::string> v7{10, "hi"};


	std::cout<<"V1"<<std::endl;
	for(auto it = v1.cbegin(); it<v1.cend(); it++)
		std::cout<<*it<<std::endl;
	std::cout<<"V2"<<std::endl;
	for(auto it = v2.cbegin(); it<v2.cend(); it++)
		std::cout<<*it<<std::endl;
	std::cout<<"V3"<<std::endl;
	for(auto it = v3.cbegin(); it<v3.cend(); it++)
		std::cout<<*it<<std::endl;
	std::cout<<"V4"<<std::endl;
	for(auto it = v4.cbegin(); it<v4.cend(); it++)
		std::cout<<*it<<std::endl;
	std::cout<<"V5"<<std::endl;
	for(auto it = v5.cbegin(); it<v5.cend(); it++)
		std::cout<<*it<<std::endl;
	std::cout<<"V6"<<std::endl;
	for(auto it = v6.cbegin(); it<v6.cend(); it++)
		std::cout<<*it<<std::endl;
	std::cout<<"V7"<<std::endl;
	for(auto it = v7.cbegin(); it<v7.cend(); it++)
		std::cout<<*it<<std::endl;

	std::cout<<v1.size()<<" "<<v2.size()<<" "<<v3.size()<<" "<<v4.size()
	    <<" "<<v5.size()<<" "<<v6.size()<<" "<<v7.size()<<std::endl;
	return 0;
}
