#include<iostream>
#include<string>
int main()
{
	//I predict that this will change the local char and not the char in s
	std::string s;
	std::cin>>s;
	for(char c : s)
	{
		c = 'X';
	}
	std::cout<<s<<std::endl;
	//the above prediction is correct
}
