#include<iostream>
int main()
{
	int arr[10];
	int ind = 0;
	for(auto &i : arr)
	{
		i = ind;
		ind++;
	}
	for(auto i : arr)
		std::cout<<i<<std::endl;
}
