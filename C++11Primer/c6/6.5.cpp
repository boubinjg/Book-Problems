#include<iostream>
int abs(int i)
{
	if(i<0)
		return -i;
	return i;
}
int main()
{
	std::cout<<abs(-5)<<" "<<abs(5)<<std::endl;
	return 0;
}
