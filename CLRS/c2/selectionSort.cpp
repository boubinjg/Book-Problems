#include<iostream>
#include<vector>
void print(std::vector<int>& a)
{
	for(auto i : a)
		std::cout<<i<<" ";
	std::cout<<std::endl;
}
void selectionSort(std::vector<int>& a)
{
	for(int i = 0; i<a.size()-1; i++) {
		int min = a[i];
		int minPos = i;
		for(int j = i+1; j<a.size(); j++) {
			if(a[j] < min) {
				min = a[j];
				minPos = j;
			}
		}
		a[minPos] = a[i];
		a[i] = min;
	}
}
int main()
{
	std::vector<int> v{5,4,3,2,1};
	print(v);
	selectionSort(v);
	print(v);
}
