#include<string>
#include<iostream>
class Quote{
public:
	Quote() = default;
	Quote(const std::string &book, double sales_price) :
		bookNo(book), price(sales_price) {} 
	std::string isbn() const {return bookNo;}
	virtual double net_price(std::size_t n) const 
		{return n * price;}
	virtual void debug() const {std::cout<<"QUOTE: "<<bookNo<<" "<<price<<std::endl;}
	virtual ~Quote() = default;
private:
	std::string bookNo;
protected:
	double price = 0.0;
};

class Disc_quote : public Quote{
public:
	Disc_quote() = default;
	Disc_quote(const std::string &book, double pr, std::size_t mqt, double disc) :
	Quote(book, pr), min_qty(mqt), discount(disc) {} 
	
	virtual void debug() const = 0;
	virtual double net_price(std::size_t n) const = 0;
private:
	std::size_t min_qty = 0;
	double discount = 0.0;
};

class Bulk_quote : public Disc_quote{
public:	
	Bulk_quote() = default;
	Bulk_quote(const std::string&, double, std::size_t, double);
	double net_price(std::size_t) const override;
	void debug() const override {std::cout<<"BULK_QUOTE: "<<isbn()<<" "<<price
			                      <<" "<<min_qty<<" "<<discount<<std::endl;} 
private:
	std::size_t min_qty = 0;
	double discount = 0.0;
};

double print_total(std::ostream &os, const Quote &item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # sold: " << n 
	<< " total due: " << ret << std::endl;

	return ret;
}
