#ifndef CPP_7_6_h
#define CPP_7_6_H

#include<iostream>
#include<string>

struct Sales_data{
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
	Sales_data& combine(const Sales_data &rhs)
	{
		units_sold += rhs.units_sold;
		revenue += rhs.revenue;
		return *this;
	}
	std::string isbn() const
	{
		return bookNo;
	}

};
std::istream &read(std::istream &is, Sales_data &item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}
std::ostream &print(std::ostream &os, const Sales_data &item)
{
	std::cout<<item.bookNo<<" "<<item.units_sold<<" "<<item.revenue<<std::endl;
	return os;
}
Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}
#endif
