#include<iostream>
#include<string>
#include<fstream>
struct Sales_data {
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
int main(int arcg, char** argv)
{
	Sales_data total;
	std::ifstream fs(argv[1]);	
	std::ofstream os(argv[2], std::ostream::app);
	if(fs>>total.bookNo>>total.units_sold>>total.revenue) {
		Sales_data trans;
		while(fs>>trans.bookNo>>trans.units_sold>>trans.revenue) {
			if(total.bookNo == trans.bookNo) {
				total.units_sold += trans.units_sold;
				total.revenue += trans.revenue;
			}
			else {
				
				os<<total.bookNo<<" "<<total.units_sold<<" "<<total.revenue<<std::endl;
				total = trans;
			}
		}
		os<<total.bookNo<<" "<<total.units_sold<<" "<<total.revenue<<std::endl;
	} else {
		os<< "No Data?" << std::endl;
	}
	return 0;
}
