#include<iostream>
int main()
{
	int a = 5, b = 6, c = 7, d = 8;
	if(a<b && b<c && c<d)
		std::cout<<"true"<<std::endl;
	else
		std::cout<<"false"<<std::endl;
	return 0;
}
