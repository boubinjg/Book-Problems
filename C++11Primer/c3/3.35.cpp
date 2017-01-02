#include<iostream>
int main()
{
	int arr[5] = {1,2,3,4,5};
	for(auto i : arr)
		std::cout<<i<<std::endl;
	std::cout<<std::endl;
	int *e = arr+5, *b = arr;
	while(b < e)
	{
		*b = 0;
		b++;
	} 

	for(auto i : arr)
		std::cout<<i<<std::endl;
	return 0;
}
