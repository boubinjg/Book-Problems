#include<iostream>
#include "Sales_item.h"
int main()
{
	Sales_item item;
	while(std::cin>>item)
	{
		std::cout<<"Sold Item "<<item.isbn()<<" Average Price: "<<item.avg_price()<<std::endl;
	}
	return 0;
}
