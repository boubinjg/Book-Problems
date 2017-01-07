#include<iostream>
//legal for values inside the arrays bounds
int &get(int *arry, int index)
{
	return arry[index];
}
int main()
{
	int ia[10];
	for (int i = 0; i!=10; i++)
		get(ia, i) = i;
	for(int i = 0; i!= 10; i++)
		std::cout<<ia[i]<<std::endl;
}
