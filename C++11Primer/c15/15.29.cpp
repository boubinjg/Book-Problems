#include<vector>
#include"15.27.h"
#include<memory>

double Bulk_quote::net_price(size_t cnt) const
{
        if(cnt >= min_qty)
                return cnt * (1-discount) * price;
        else
                return cnt * price;
}


int main()
{
	std::vector<std::shared_ptr<Quote>> q;
	q.push_back(std::make_shared<Bulk_quote>("asdf", 10, 10, .5));
	q.push_back(std::make_shared<Bulk_quote>("egfg", 10, 5, .5));
	int total = 0;
	for(auto bq : q)
		total += q.back()->net_price(100);
	std::cout<<total<<std::endl;
}
