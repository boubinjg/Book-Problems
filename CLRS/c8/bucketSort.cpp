#include<iostream>
#include<vector>
#include<algorithm>
#include<random>
template <typename T>
void print(std::vector<T> v)
{
	for(auto i : v)
		std::cout<<i<<" ";
	std::cout<<std::endl;
}
double myRand()
{
	static std::default_random_engine e;
	std::uniform_real_distribution<double> d;
	return d(e);
}
void bucketSort(std::vector<double>& a)
{
	std::vector<std::vector<double>> b(a.size());	
	int n = b.size();
	for(int i = 0; i<a.size(); i++) {
		b[n*a[i]].push_back(a[i]);
	}
	for(int i = 0; i<b.size(); i++)
		std::sort(b[i].begin(), b[i].end());
	int index = 0;
	for(int i = 0; i<b.size(); i++) {
		for(auto d : b[i]) {
			a[index] = d;
			++index;
		}
	}
}
int main()
{
	std::vector<double> v;
	for(int i = 0; i<10; i++)
		v.push_back(myRand());
	bucketSort(v);
	print(v);
}
