#include<iostream>
int main()
{
	int arr[5] = {1,2,3,4,5};
	int *p1 = arr, *p2 = arr+2;
	//p1 is set to p2
	p1 += p2-p1;
	std::cout<<*p1<<" "<<*p2<<std::endl;
}
