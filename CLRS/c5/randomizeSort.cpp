#include<iostream>
#include<vector>
#include<random>
#include<algorithm>
struct randomObj {
	int val, index;
};
void print(std::vector<int>& v)
{
	for(auto i : v)
		std::cout<<i<<" ";
	std::cout<<std::endl;
}
int random(int a, int b)
{
	static std::default_random_engine e;
	std::uniform_int_distribution<> r(a,b);
	return r(e);
}
void randomSort(std::vector<int>& v)
{	
	std::vector<randomObj> p(v.size());
	for(int i = 0; i<p.size(); i++) {
		p[i].index = random(1, pow(v.size(),3));
		p[i].val = v[i];
	}
	std::sort(p.begin(), p.end(), [](randomObj i, randomObj j){return i.index < j.index;});		
	for(int i = 0; i<p.size(); i++)
		v[i] = p[i].val;
}
int main()
{
	std::vector<int> v{1,2,3,4,5,6,7,8,9,10};
	randomSort(v);
	print(v);
}
