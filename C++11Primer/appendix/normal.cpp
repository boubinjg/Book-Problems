#include<random>
#include<iostream>

int main()
{
	std::default_random_engine e;
	
	//normal distribution
	std::normal_distribution<double> n(5, 100);
	std::cout<<n(e)<<std::endl;
	
	//lognormal distribution
	std::lognormal_distribution<double> ln(5, 10);
	std::cout<<n(e)<<std::endl;

	//chi squared
	std::chi_squared_distribution<double> c(1.5);
	std::cout<<c(e)<<std::endl;

	//cauchy distribution
	std::cauchy_distribution<double> ch(.5, 25.6);
	std::cout<<ch(e)<<std::endl;

	//fisher f distribution
	std::fisher_f_distribution<double> f(1, 5);
	std::cout<<f(e)<<std::endl;

	//students t distribution
	std::student_t_distribution<double> t(5);
	std::cout<<t(e)<<std::endl;

	return 0;
}
