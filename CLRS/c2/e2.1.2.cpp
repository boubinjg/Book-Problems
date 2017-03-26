#include<iostream>
#include<vector>
void print(std::vector<int>& a)
{
	for(auto i : a)
		std::cout<<i<<" ";
	std::cout<<std::endl;
}
void insertionSortDec(std::vector<int>& a)
{
	for(int j = 1; j<a.size(); j++) {
		int key = a[j];
		int i = j-1;
		while(i >= 0 && a[i] < key) {
			a[i+1] = a[i];
			--i;
		}
		a[i+1] = key;
	}
}
int main()
{
	std::vector<int> v{1,2,3,4,5};
	print(v);
	insertionSortDec(v);
	print(v);
}
