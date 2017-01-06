#include<iostream>
#include<exception>
int main()
{
	int i, j;
	std::cin>>i>>j;
	try{
		if(j == 0)
			throw std::exception();
		std::cout<<i/j<<std::endl;
	}catch(std::exception e){
		std::cout<<"Divide by zero"<<std::endl;
	}
}
