#include"15.30.h"
int main()
{
	Basket b;
	Quote q("asdf", 15);
	Bulk_quote bq("gggg", 50, 10, .25);

	b.add_item(q);
	b.add_item(bq);

	b.total_receipt(std::cout);
}
