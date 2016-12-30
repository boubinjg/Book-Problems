#include<iostream>
#include<string>
#include"Sales_item.h"
int main()
{
	Sales_item item1, ret;
	std::string isbn;
	std::cout<<"Please enter some sales items with the same ISBN"<<std::endl;
	
	if(std::cin>>item1)
	{
		isbn = item1.isbn();
		ret = item1;
		while(std::cin>>item1)
		{
			if(item1.isbn() != isbn)	
			{
				std::cerr<<"Different ISBNs"<<std::endl;
				return 0;
			}
			ret += item1;
		}
	}
	std::cout<<ret<<std::endl;
	return 0;
}
