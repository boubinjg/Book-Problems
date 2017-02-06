#include<random>
#include<iostream>
int main()
{
	std::default_random_engine e(time(0));
	std::uniform_int_distribution<unsigned> u(0,RAND_MAX);
	for(int i = 0; i<10; i++)
		std::cout<<u(e)<<std::endl;
	return 0;
}
