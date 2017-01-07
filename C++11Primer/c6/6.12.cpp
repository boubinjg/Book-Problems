#include<iostream>
void swap(int& i, int& j)
{
	int temp = i;
	i = j;
	j = temp;
}
int main()
{
	int i = 0, j = 1;
	std::cout<<i<<" "<<j<<std::endl;
	swap(i, j);
	std::cout<<i<<" "<<j<<std::endl;
	return 0;
}
