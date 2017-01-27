#include<string>
#include<iostream>
#include"15.3.h"
class Max_quote : public Quote{
public:	
	Max_quote() = default;
	Max_quote(const std::string&, double, std::size_t, double, size_t);
	double net_price(std::size_t) const override;
private:
	size_t min_qty = 0, max_qty;
	double discount = 0.0;
};
