#include<random>
#include<iostream>

int main()
{
	std::default_random_engine e;
	
	//poisson distribution
	std::poisson_distribution<unsigned> p(500);
	std::cout<<p(e)<<std::endl;	

	//exponential distribution
	std::exponential_distribution<double> exp(1.5);
	std::cout<<exp(e)<<std::endl;

	//gamma distribution
	std::gamma_distribution<double> gam(5, 10);
	std::cout<<gam(e)<<std::endl;

	//weibull distribution
	std::weibull_distribution<double> w(5, 10);
	std::cout<<w(e)<<std::endl;

	//extreme value distribution
	std::extreme_value_distribution<double> ext(0.0, 5.0);
	std::cout<<ext(e)<<std::endl;
	
	return 0;
}
