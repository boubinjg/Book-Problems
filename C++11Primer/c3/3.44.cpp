#include<iostream>
int main()
{
	int ia[3][4] = {{1,2,3,4},
		        {5,6,7,8},
			{9,10,11,12}};

	using intArr = int[4];
	for(intArr *p = ia; p != ia+3; p++)
	{
		for(int *q = *p; q != (*p)+4; q++)
			std::cout<<*q<<" ";
		std::cout<<std::endl;
	}
}
