#include<vector>
#include<algorithm>
#include<iostream>
#include<string>
template <typename T>
int countVal(const std::vector<T>& v, const T& t)
{
	return std::count_if(v.begin(), v.end(), [t](T tv){return t == tv;});
}
int main()
{
	std::vector<int> vi{1,2,1,3,1,4,1,5};
	std::cout<<countVal(vi, 1)<<std::endl;
	std::vector<double> vd{0.0, 1,5, 6.3, 0.0, 6.66};
	std::cout<<countVal(vd, 0.0)<<std::endl;
	std::vector<std::string> vs{"asdf", "sdfgsfg", "asdf"};
	std::cout<<countVal(vs, std::string("asdf"))<<std::endl;
	return 0;
}
