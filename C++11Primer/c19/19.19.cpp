#include "14.2.h"
#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
bool pred(Sales_data s, double  d)
{
	auto f = std::mem_fn(&Sales_data::averagePrice);
	return f(s) > d;
}
std::vector<Sales_data>::iterator findFirstGT(std::vector<Sales_data> v, double d)
{
	
	auto it = std::find_if(v.begin(), v.end(), std::bind(pred,std::placeholders::_1, d));
	return it;
}
int main()
{
	Sales_data s0;
	Sales_data s1("asdf", 5, 5);
	std::vector<Sales_data> d;
	
	d.push_back(s0);
	d.push_back(s1);
	
	auto it = findFirstGT(d, 4);
	std::cout<<it->averagePrice()<<std::endl;
	
	return 0;
}
