#include<random>
#include<iostream>
int main()
{
	std::cout<<"Please provide a seed: "<<std::endl;
	int seed;
	std::cin>>seed;
	std::default_random_engine e(seed);
	
	int min, max;
	std::cout<<"Please provide a min and max for the range"<<std::endl;
	std::cin>>min>>max;
	std::uniform_int_distribution<unsigned> u(min,max);
	for(int i = 0; i<10; i++)
		std::cout<<u(e)<<std::endl;
	return 0;
}
