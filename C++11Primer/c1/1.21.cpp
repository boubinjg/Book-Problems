#include<iostream>
#include"Sales_item.h"
int main()
{
	Sales_item item1, item2, ret;
	std::cout<<"Please enter two sales items with the same ISBN"<<std::endl;
	std::cin>>item1>>item2;
	
	if(item1.isbn() != item2.isbn())	
	{
		std::cerr<<"Different ISBNs"<<std::endl;
		return 0;
	}
	ret = item1+item2;
	std::cout<<ret<<std::endl;
	return 0;
}
