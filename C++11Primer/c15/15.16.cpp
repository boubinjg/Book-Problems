#include"15.16.h"

Max_quote::Max_quote(const std::string& book, double p, size_t qty, double disc, size_t mqty) :
        Disc_quote(book, p, qty, disc), max_qty(mqty) {}

double Max_quote::net_price(size_t cnt) const
{
        if(cnt >= max_qty || cnt<min_qty)
                return cnt * price;
        else
                return cnt * (1-discount) * price;
}

Bulk_quote::Bulk_quote(const std::string& book, double p, size_t qty, double disc) :
	Disc_quote(book, p, qty, disc) {}

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
	Max_quote m("ffffff", 10, 10, 10, 10);
	q.debug();
	b.debug();
	m.debug();
}
