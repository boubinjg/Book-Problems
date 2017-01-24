#include"14.2.h"
Sales_data::Sales_data(std::istream &is)
{
	is >> *this;
}
Sales_data& Sales_data::operator+=(const Sales_data& rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}
std::istream& operator>>(std::istream& is, Sales_data& rhs)
{
	double price;
	is>>rhs.bookNo>>rhs.units_sold>>price;
	if(is)
		rhs.revenue = rhs.units_sold * price;
	else
		rhs = Sales_data();
	return is;
}
std::ostream& operator<<(std::ostream& os, const Sales_data& rhs)
{
	os<<rhs.bookNo<<rhs.units_sold<<rhs.revenue;
	return os;
}
Sales_data operator+(Sales_data& lhs, Sales_data& rhs)
{
	Sales_data ret = rhs;
	ret += rhs;
	return ret;
}
