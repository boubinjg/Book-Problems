#include<iostream>
class fob{
public:
	fob() = default;
	int operator()(int one, int two, int three) 
	{
		int ret;
		one>10 ? (ret = two) : (ret = three);
		return ret;
	}
};
int main()
{
	fob f;
	std::cout<<f(1,2,3)<<" "<<f(100, 200, 300)<<std::endl;
	return 0;
}
