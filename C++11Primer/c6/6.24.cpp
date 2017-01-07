#include<iostream>
//the issue with this function is that it only prints arrays of size 10.
//using one of the other methods would allow you to print an arbitrary number of characters
void print(const int ia[10])
{
	for(size_t i = 0; i!= 10; i++)
		std::cout<<ia[i]<<std::endl;	
}
int main()
{
	int ia[10] = {1,2,3,4,5,6,7,8,9,0};
	print(ia);
}
