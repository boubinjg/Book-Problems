#include"16.24.h"
#include<iostream>
int main()
{
	Blob<int> b();
	int i = 10;
	b.push_back(i);
	std::cout<<b[0]<<std::endl;
}
