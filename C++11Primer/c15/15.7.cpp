#include"15.7.h"

Max_quote::Max_quote(const std::string& book, double p, size_t qty, double disc, size_t mqty) :
	Quote(book, p), min_qty(qty), discount(disc), max_qty(mqty) {}

double Max_quote::net_price(size_t cnt) const 
{
	if(cnt >= max_qty || cnt<min_qty)
		return cnt * price;
	else
		return cnt * (1-discount) * price;
}

int main()
{
	Quote q("abcd", 5);
	Max_quote m("efgh", 10, 5, .5, 10);
	print_total(std::cout, q, 5);
	print_total(std::cout, m, 10);	
}
