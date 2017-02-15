#include<random>
#include<iostream>
#include<vector> 
int main()
{
	std::default_random_engine e;
	std::vector<int> v{1,2,3,4,5,6,7,8};	

	//discrete distribution (also takes initializer list)
	std::discrete_distribution<unsigned> d(5, 10);
	std::cout<<d(e)<<std::endl;

	//piecewise constant distribution
	std::piecewise_constant_distribution<double> pc(v.begin(), v.end(), v.begin()+4);
	std::cout<<pc(e)<<std::endl;	

	std::piecewise_linear_distribution<double> pl(v.begin(), v.end(), v.begin()+4);
	std::cout<<pl(e)<<std::endl;
	
	return 0;
}
