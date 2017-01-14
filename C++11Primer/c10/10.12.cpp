#include "Sales_data.h"
#include<iostream>
#include<vector>
#include<algorithm>
bool compISBN(Sales_data s1, Sales_data s2)
{ return s1.isbn() < s2.isbn(); }
int main()
{
	std::vector<Sales_data> sv(100);
	
	int i = 0;
	for(auto sd : sv) {
		sv[i] = Sales_data(std::to_string(100-i));
		i++;
	}
	
	std::sort(sv.begin(), sv.end(), compISBN);

	for(auto sd : sv)
		std::cout<<sd.isbn()<<" ";
	std::cout<<std::endl;
	
	return 0;
}
