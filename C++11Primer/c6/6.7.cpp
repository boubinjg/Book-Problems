#include<iostream>
int func()
{
	static int i = -1;
	++i;
	return i;
}
int main()
{
	for(int i = 0; i<10; i++)
		std::cout<<func()<<std::endl;
	return 0;
}
