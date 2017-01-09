#include<iostream>
#include<string>
#include "7.6.h"    
int main()
{
	Sales_data total;
	if(read(std::cin, total)) {
		Sales_data trans;
		while(read(std::cin, trans)) {
			if(total.isbn() == trans.isbn()) {
				total.combine(trans);
			}
			else {
				print(std::cout, total);
				total = trans;
			}
		}
		std::cout<<total.bookNo<<" "<<total.units_sold<<" "<<total.revenue<<std::endl;
	} else {
		std::cerr << "No Data?" << std::endl;
	}
	return 0;
}
