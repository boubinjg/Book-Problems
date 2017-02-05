#ifndef SALES_DATA
#define SALES_DATA
#include <string>
#include <iostream>
#include <unordered_map>
class Sales_data {
	friend std::istream& operator>>(std::istream&, Sales_data&);
	friend std::ostream& operator<<(std::ostream&, const Sales_data&);
	friend bool operator==(const Sales_data&, const Sales_data&);
	friend bool operator!=(const Sales_data&, const Sales_data&);
	friend class std::hash<Sales_data>;
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

	double averagePrice() const {return units_sold ? revenue/units_sold : 0;}
private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
std::istream& operator>>(std::istream& is, Sales_data& rhs);
std::ostream& operator<<(std::ostream&, const Sales_data&);
bool operator==(const Sales_data&, const Sales_data&);
bool operator!=(const Sales_data&, const Sales_data&);

bool operator==(const Sales_data& rhs, const Sales_data&lhs)
{
	return lhs.bookNo == rhs.bookNo && 
	       lhs.units_sold == rhs.units_sold &&
	       lhs.revenue == rhs.revenue;
}
bool operator!=(const Sales_data& rhs, const Sales_data& lhs)
{
	return !(lhs == rhs);
}
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
Sales_data Sales_data::operator+(Sales_data& rhs) 
{ 
        Sales_data ret = *this; 
        ret += rhs; 
        return ret; 
} 
Sales_data& Sales_data::operator+=(Sales_data& rhs) 
{ 
        if(bookNo == rhs.bookNo) { 
                units_sold += rhs.units_sold; 
                revenue += rhs.revenue; 
        } 
        return *this; 
} 
Sales_data& Sales_data::operator=(std::string s) 
{ 
        bookNo = s; 
        return *this; 
}
#endif
