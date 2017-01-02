#include<iostream>
#include<vector>
int main()
{
	int arr[10];
	int ind = 0;
	for(auto &i : arr)
	{
		i = ind;
		ind++;
	}
	std::cout<<"array"<<std::endl;
	for(auto i : arr)
		std::cout<<i<<" ";
	std::cout<<std::endl;

	int arr2[10];
	std::cout<<"array copy"<<std::endl;
	for(size_t i = 0; i<10; i++)
		arr2[i] = arr[i];
	
	for(auto i : arr2)
		std::cout<<i<<" ";
	std::cout<<std::endl;

	std::vector<int> v;
	std::cout<<"vector"<<std::endl;
	for(size_t i = 0; i<10; i++)
		v.push_back(arr[i]);
	
	for(auto i : v)
		std::cout<<v[i]<<" ";
	std::cout<<std::endl;
}
