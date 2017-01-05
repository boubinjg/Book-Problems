#include<iostream>
#include<string>
int main()
{
	std::string s1, s2,res;
	do{
		std::cout<<"Please enter two strings"<<std::endl;
		std::cin>>s1>>s2;

		if(s1>s2)
			std::cout<<s1<<" is greater"<<std::endl;
		else if(s1 == s2)
			std::cout<<"The strings are equal"<<std::endl;
		else
			std::cout<<s2<<" is greater"<<std::endl;

		std::cout<<"press q to quit, any other key to continue"<<std::endl;
		std::cin>>res;
	}while(!res.empty() && res[0] != 'q');
}
