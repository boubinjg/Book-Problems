#include<vector>
#include<iostream>
template <typename T>
void print(std::vector<T> v)
{
	for(auto i : v)
		std::cout<<i<<" ";
	std::cout<<std::endl;
}
template <typename T>
void countingSort(std::vector<T>& A, std::vector<T> B, int k)
{
	std::vector<T> C(k+1);
	for(int j = 0; j<A.size(); ++j) 
		C[A[j]] = C[A[j]] + 1; 
	for(int i = 1; i<=k; ++i)
		C[i] += C[i-1];
	for(int j = A.size()-1; j>=0; --j){
		B[C[A[j]]-1] = A[j];
		C[A[j]] = C[A[j]] - 1;
	}
	
	A = B;
}
int main()
{
	std::vector<int> A{2,5,3,0,2,3,0,3},B(A.size());
	print(A);
	countingSort(A, B, 5);
	print(A);
	return 0;
}
