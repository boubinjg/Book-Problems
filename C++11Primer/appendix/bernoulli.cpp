#include<random>
#include<iostream>
int main()
{
	std::default_random_engine e;
	
	//bernouli distribution
	std::bernoulli_distribution b(.5);
	std::cout<<std::boolalpha<<b(e)<<std::endl;

	//binomial distribution
	std::binomial_distribution<unsigned> bin(1, .5);
	std::cout<<bin(e)<<std::endl;

	//geometric distribution
	std::geometric_distribution<unsigned> g(.5);
	std::cout<<g(e)<<std::endl;

	//negative binomial distribution
	std::negative_binomial_distribution<unsigned> nbin(1, .5);
	std::cout<<nbin(e)<<std::endl;

	return 0;
}
