#include<vector>
#include<iostream>
#include<random>
int rand(int beg, int end) 
{
	static std::default_random_engine e;
	std::uniform_int_distribution<int> d(beg, end);
	return d(e);
}
int partition(std::vector<int>& v, int beg, int end) 
{
	int pval = v[end];
	int i = beg-1;
	for(int j = beg; j<end; j++) {
		if(v[j] <= pval) {
			++i;
			std::swap(v[i], v[j]);
		}
	}
	++i;
	std::swap(v[i],v[end]);
	return i;
}
int randpartition(std::vector<int>& v, int beg, int end)
{
	int p = rand(beg, end);
	std::swap(v[p], v[end]);
	return partition(v, beg, end);
}
int randomizedselect(std::vector<int>& v, int beg, int end, int i)
{
	
	while(beg != end) {
		int q = randpartition(v, beg, end);
		int k = q-beg + 1;
		if(i == k)
			return v[q];
		else if(i < k)
			end = q-1;
		else {
			beg = q+1;
			i = i-k;
		}
	}
	return v[beg];
}
int main()
{
	std::vector<int> v{1,4,5,2,3,9,50,22,-10,-40,100};
	int i = randomizedselect(v, 0, v.size()-1, 8);
	std::cout<<i<<std::endl;
	
	return 0;
}
