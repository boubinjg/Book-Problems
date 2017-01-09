#include<iostream>
#include<string>
#include "7.21.h"    
int main()
{
	Sales_data total(std::cin);
	if(!total.isbn().empty()) {
		Sales_data trans(std::cin);
		while(!trans.isbn().empty()) {
			if(total.isbn() == trans.isbn()) {
				total.combine(trans);
			}
			else {
				print(std::cout, total);
				total = trans;
			}
			read(std::cin, trans);
		}
		print(std::cout, total);
	} else {
		std::cerr << "No Data?" << std::endl;
	}
	return 0;
}
