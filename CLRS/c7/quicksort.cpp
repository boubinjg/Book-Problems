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
		if(v[j] >= pval) {
			++i;
			std::swap(v[i], v[j]);
			print(v);
		}
	}
	++i;
	std::swap(v[i],v[end]);
	return i;
}
void quicksort(std::vector<int>& v, int beg, int end)
{
	if(beg < end) {
		int p = partition(v, beg, end);
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
