#include<iostream>
#include<string>
std::string sa[10];
//initialized
int ia[10];
int main()
{
	std::string sa2[10];
	//not initialized
	int ia2[10];
	for(int i = 0; i<10; i++)
	{
		std::cout<<sa[i]<<" "<<ia[i]<<" "<<sa2[i]<<" "<<ia2[i]<<std::endl;
	}
}
