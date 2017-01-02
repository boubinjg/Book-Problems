#include<iostream>
int main()
{
	int ia[3][4] = {{1,2,3,4},
		        {5,6,7,8},
			{9,10,11,12}};

	for(auto &p : ia)
	{
		for(auto &q : p)
			std::cout<<q<<" ";
		std::cout<<std::endl;
	}
}
