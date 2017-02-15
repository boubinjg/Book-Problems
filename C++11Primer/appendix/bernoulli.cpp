#include<random>
#include<iostream>
int main()
{
	std::default_random_engine e;
	
	//creates a uniform int distribution from 0 to 10
	std::uniform_int_distribution<unsigned> ui(0, 10);
	std::cout<<ui(e)<<std::endl;
	//creates a uniform distribution of real numbers from 0 to 1
	std::uniform_real_distribution<double> ur(0,1);
	std::cout<<ur(e)<<std::endl;

	return 0;
}
