#include<iostream>
#include<string>
#include"Sales_item.h"
#include<unordered_map>
//Records for each ISBN must be grouped together, as specified in the book
int main()
{
	Sales_item val, curval;
	std::string isbn;
	std::cout<<"Please enter some sales items with the same ISBN"<<std::endl;
	
	if(std::cin>>curval)
	{
		int count = 1;
		while(std::cin>>val)
		{
			if(val.isbn() == curval.isbn())
				count++;
			else
			{
				std::cout<<curval.isbn()<<" "<<count<<std::endl;
				curval = val;
				count = 1;
			}
		}
		std::cout<<curval.isbn()<<" "<<count<<std::endl;
	}
	return 0;
}
