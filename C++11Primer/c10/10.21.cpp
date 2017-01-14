#include<iostream>
int main()
{
	int i = 10;
	auto f = [&]()->bool{return (i>0 ? i-- : false);};
	for(int i = 0; i<15; i++)
		std::cout<<i<<" "<<f()<<std::endl;
}
