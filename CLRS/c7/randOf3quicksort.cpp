#include<vector>
#include<iostream>
#include<random>
int rand(int beg, int end) 
{
	static std::default_random_engine e;
	std::uniform_int_distribution<int> d(beg, end);
	return d(e);
}
void print(std::vector<int>& v) 
{
	for(auto i : v)
		std::cout<<i<<" ";
	std::cout<<std::endl;
}
int partition(std::vector<int>& v, int beg, int end) 
{
	int pval = v[end];
	int i = beg-1;
	for(int j = beg; j<end; j++) {
		if(v[j] <= pval) {
			++i;
			std::swap(v[i], v[j]);
			print(v);
		}
	}
	++i;
	std::swap(v[i],v[end]);
	return i;
}
int randpartition(std::vector<int>& v, int beg, int end)
{
	int p = (rand(beg, end) + rand(beg,end) + rand(beg,end))/3;
	std::swap(v[p], v[end]);
	return partition(v, beg, end);
}
void quicksort(std::vector<int>& v, int beg, int end)
{
	if(beg < end) {
		int p = randpartition(v, beg, end);
		quicksort(v, beg, p-1);
		quicksort(v, p+1, end);
	}
}
int main()
{
	std::vector<int> v{1,4,5,2,3};
	print(v);
	quicksort(v, 0, v.size()-1);
	print(v);
	return 0;
}
