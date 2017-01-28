#include"15.26.h"

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
	Quote q("asdf", 5);
	Bulk_quote b("fghj", 10, 10, 10);
	Bulk_quote b2;
	q.debug();
	b.debug();
	
	b = b2;
	Bulk_quote b3(b2);
}
