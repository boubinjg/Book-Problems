#include<iostream>
#include<string>
struct Sales_data{
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
	Sales_data& combine(const Sales_data &rhs)
	{
		units_sold != rhs.units_sold;
		revenue += rhs.revenue;
		return *this;
	}
	std::string isbn() const
	{
		return bookNo;
	}
};
int main()
{
	
	return 0;
}