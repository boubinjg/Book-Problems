#include<iostream>
void swap(int* i, int* j)
{
	int temp = *i;
	*i = *j;
	*j = temp;
}
int main()
{
	int i = 0, j = 1;
	int *ip = &i, *jp = &j;
	std::cout<<i<<" "<<j<<std::endl;
	swap(ip, jp);
	std::cout<<i<<" "<<j<<std::endl;
	return 0;
}
