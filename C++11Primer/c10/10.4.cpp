#include<iostream>
#include<vector>
#include<algorithm>
int main()
{
	std::vector<double> d{1.1,2.2,3.3,4.4,5.5};
	std::cout<<std::accumulate(d.begin(),d.end(), 0)<<std::endl;
	return 0;
}
