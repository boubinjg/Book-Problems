#include"15.27.h"

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

	q.debug();
	b.debug();
}
