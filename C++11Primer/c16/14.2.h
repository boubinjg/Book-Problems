#ifndef SALES_DATA
#define SALES_DATA
#include <string>
#include <iostream>
class Sales_data {
	friend std::istream& operator>>(std::istream&, Sales_data&);
	friend std::ostream& operator<<(std::ostream&, const Sales_data&);
	friend bool operator==(Sales_data&, Sales_data&);
	friend bool operator!=(Sales_data&, Sales_data&);
	
public:
	Sales_data(const std::string &s, unsigned n, double p) 
		: bookNo(s), units_sold(n), revenue(n*p) {}
	Sales_data() : Sales_data("", 0, 0.0f){}
	Sales_data(const std::string &s) :Sales_data(s, 0, 0.0f){}
	Sales_data(std::istream &is);
	
	Sales_data& operator+=(const Sales_data&);
	std::string isbn() const {return bookNo;}
	
	Sales_data operator+(Sales_data&);
	Sales_data& operator+=(Sales_data&);
	Sales_data& operator=(std::string);
	
	operator double() { return revenue; }
	operator std::string() { return bookNo; }

private:
	double averagePrice() const {return units_sold ? revenue/units_sold : 0;}
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
std::istream& operator>>(std::istream& is, Sales_data& rhs);
std::ostream& operator<<(std::ostream&, const Sales_data&);
bool operator==(Sales_data&, Sales_data&);
bool operator!=(Sales_data&, Sales_data&);
#endif
