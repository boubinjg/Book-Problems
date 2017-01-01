#include<iostream>
#include<string>
#include "Sales_data.h"
int main()
{
	//ex 1.20
	std::cout<<"1.20"<<std::endl;
	Sales_data s1, s2;
	while(std::cin>>s2.bookNo>>s2.units_sold>>s2.revenue)
	{
		std::cout<<s1.bookNo<<" "<<s1.units_sold<<" "
		         <<s1.revenue+s2.revenue;
	}

	//ex 1.21	
	std::cout<<"1.21"<<std::endl;
	std::cin>>s1.bookNo>>s1.units_sold>>s1.revenue;
	std::cin>>s2.bookNo>>s2.units_sold>>s2.revenue;
	if(s1.bookNo == s2.bookNo)
	{
		std::cout<<s1.units_sold+s2.units_sold<<" "
		         <<s1.revenue+s2.revenue;
	}
	else
		std::cerr<<"incorrect book numbers"<<std::endl;

	
	return 0;
}
