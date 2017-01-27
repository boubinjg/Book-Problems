#include"15.3.h"

Bulk_quote::Bulk_quote(const std::string& book, double p, size_t qty, double disc) :
	Quote(book, p), min_qty(qty), discount(disc) {}

double Bulk_quote::net_price(size_t cnt) const 
{
	if(cnt >= min_qty)
		return cnt * (1-discount) * price;
	else
		return cnt * price;	
}

int main()
{
	Quote q("abcd", 5);
	Bulk_quote b("efgh", 10, 5, .5);
	print_total(std::cout, q, 5);
	print_total(std::cout, b, 10);	
}
