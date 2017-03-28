#include<iostream>
#include<vector>
#include<cmath>
/*
	The worstcase running time of hornersRule is n.

	The from-scratch solution has a similar complexity depending on 
	wether pow is a linear or constant function. If linear, the complexity of the new
	function is n^2
*/
int fromScratch(const std::vector<int>& v, int x)
{
	int y = 0;
	for(int n = 0; n<v.size(); n++)
	{
		y += v[n]*pow(x, n);
	}
	return y;
}
int hornersRule(const std::vector<int>& v, int x)
{
	int y = 0;
	for(int n = v.size()-1; n>=0; n--) {
		y = v[n] + x * y;
	}
	return y;
}
int main()
{
	std::vector<int> v{1,2,3,4,5};
	std::cout<<hornersRule(v, 2)<<std::endl;
	std::cout<<fromScratch(v, 2)<<std::endl;
}
