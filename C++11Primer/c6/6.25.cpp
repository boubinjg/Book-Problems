#include<iostream>
#include<cstring>
int main(int argc, char** argv)
{
	if(argc != 3)
		std::cout<<"3 args please"<<std::endl;
	std::cout<<strcat(argv[1],argv[2])<<std::endl;
	return 0;
}
