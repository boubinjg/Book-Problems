#include<iostream>
void swap(int *&i, int *&j)
{
	int *temp = i;
	i = j;
	j = temp;
}
int main()
{
	int i = 5, j = 0;
	int *ip = &i, *jp = &j;

	std::cout<<*ip<<" "<<*jp<<std::endl;
	swap(ip,  jp);
	std::cout<<*ip<<" "<<*jp<<std::endl;	

	return 0;
}
