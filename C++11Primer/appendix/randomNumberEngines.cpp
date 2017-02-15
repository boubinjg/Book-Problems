#include<iostream>
#include<random>
static std::uniform_real_distribution<double> rd(0,1);
template <typename T>
void printEngine(T eng)
{
	for(int i = 0; i<10; i++)
		std::cout<<rd(eng)<<" ";
	std::cout<<std::endl;
}
int main()
{

	//default random
	std::default_random_engine e;
	printEngine(e);
	
	//linear congruent
	std::minstd_rand0 l;
	printEngine(l);
	
	//mersenne twister (64 bit)
	std::mt19937_64 m;
	printEngine(m);

	//subtract with carry (64 bit)
	std::ranlux48_base s;
	printEngine(s);

	//discard block
	std::ranlux48 d;
	printEngine(d);
	

	return 0;
}
