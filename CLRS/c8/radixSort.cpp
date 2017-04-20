#include<iostream>
#include<vector>
#include<cmath>
template <typename T>
void print(std::vector<T> v)
{
	for(auto i : v)
		std::cout<<i<<" ";
	std::cout<<std::endl;
}
void countingSort(std::vector<int>& a, unsigned k, int exp)
{
	std::vector<int> b(a.size()),c(k+1);
	int div = pow(10,exp);
	for(int i = 0; i<a.size(); ++i)
		++c[(a[i]%(div*10))/div];
	for(int i = 0; i<c.size(); ++i)
		c[i] += c[i-1];	
	for(int i = a.size()-1; i>=0; --i) {
		b[c[(a[i]%(div*10))/div]-1] = a[i];
		--c[(a[i]%(div*10))/div];
	}	
	a = b;
}
void radixSort(std::vector<int>& a, unsigned d)
{
	for(int i = 0; i<d; i++){
		countingSort(a, 9, i);
	}
} 
int main()
{	
	std::vector<int> v{245,554,900,452,373,864,213,672,771};
	print(v);
	radixSort(v, 3);
	print(v);
	return 0;
}
