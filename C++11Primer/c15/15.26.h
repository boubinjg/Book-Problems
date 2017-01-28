#include<string>
#include<iostream>
class Quote{
	friend bool operator!=(const Quote& lhs, const Quote& rhs);
public:
	Quote() = default;
	Quote(const std::string &book, double sales_price) :
		bookNo(book), price(sales_price) {} 
	std::string isbn() const {return bookNo;}
	
	Quote(const Quote& rhs) : price(rhs.price), bookNo(rhs.bookNo) 
	{std::cout<<"Quote copy"<<std::endl;}
	Quote(const Quote&& rhs) noexcept : price(std::move(rhs.price)), bookNo(std::move(rhs.bookNo)) 
	{std::cout<<"Quote move"<<std::endl;}
	Quote& operator=(const Quote& rhs) 
	{
		if(rhs != *this) {
			bookNo = rhs.bookNo;
			price = rhs.price;
		}
		std::cout<<"Quote copy assign"<<std::endl;
		return *this;
	}
	Quote& operator=(const Quote&& rhs) noexcept 
	{
		if(rhs != *this) {
			bookNo = std::move(rhs.bookNo);
			price = std::move(rhs.price);
		}
		std::cout<<"Quote move assign"<<std::endl;
		return *this;
	}

	virtual double net_price(std::size_t n) const 
		{return n * price;}
	virtual void debug() const {std::cout<<"QUOTE: "<<bookNo<<" "<<price<<std::endl;}
	virtual ~Quote() = default;
private:
	std::string bookNo;
protected:
	double price = 0.0;
};

class Bulk_quote : public Quote{
	friend bool operator!=(const Bulk_quote& lhs, const Bulk_quote& rhs);
public:	
	Bulk_quote() = default;
	Bulk_quote(const std::string&, double, std::size_t, double);
	double net_price(std::size_t) const override;
	void debug() const override {std::cout<<"BULK_QUOTE: "<<isbn()<<" "<<price
		                      <<" "<<min_qty<<" "<<discount<<std::endl;} 
		
	Bulk_quote(const Bulk_quote& rhs) : Quote(rhs), min_qty(rhs.min_qty), discount(rhs.discount) 
	{std::cout<<"Bulk_quote copy"<<std::endl;}
	Bulk_quote(const Bulk_quote&& rhs) noexcept : Quote(std::move(rhs)), min_qty(std::move(rhs.min_qty)),
	discount(std::move(rhs.discount)) {std::cout<<"Bulk_quote move";}
	Bulk_quote& operator=(const Bulk_quote& rhs)
	{
		if(*this != rhs) {
			Quote::operator=(rhs);
			discount = rhs.discount;
			min_qty = rhs.min_qty;
		}
		std::cout<<"Bulk_quote move"<<std::endl;
		return *this;
	}
	Bulk_quote& operator=(const Bulk_quote&& rhs) noexcept
	{
		if(*this != rhs) {
			Quote::operator=(std::move(rhs));
			discount = rhs.discount;
			min_qty = rhs.min_qty;
		}
		std::cout<<"Bulk_quote move assign"<<std::endl;
		return *this;
	}

private:
	size_t min_qty = 0;
	double discount = 0.0;
};

double print_total(std::ostream &os, const Quote &item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # sold: " << n 
	<< " total due: " << ret << std::endl;

	return ret;
}
bool operator!=(const Quote& lhs, const Quote& rhs)
{
	return (lhs.bookNo == rhs.bookNo) && (lhs.price == rhs.price);
}
bool operator!=(const Bulk_quote& lhs, const Bulk_quote& rhs)
{
	return  operator!=(Quote(rhs), Quote(lhs)) && 
	        lhs.discount == rhs.discount && 
		lhs.min_qty == rhs.min_qty;
}
