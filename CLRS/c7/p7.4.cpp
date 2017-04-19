#include<vector>
#include<iostream>
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
void tailRecursiveQuicksort(std::vector<int>& v, int p, int r)
{
	while(p < r) {
		int q = partition(v, p, r);
		tailRecursiveQuicksort(v, p, q-1);
		p = q+1;
	}
}
int main()
{
	std::vector<int> v{1,4,5,2,3};
	print(v);
	tailRecursiveQuicksort(v, 0, v.size()-1);
	print(v);
	return 0;
}
