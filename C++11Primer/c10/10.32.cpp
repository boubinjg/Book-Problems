#include<iostream>
#include<string>
#include"Sales_item.h"
#include<vector>
#include<iterator>
#include<algorithm>
#include<numeric>
int main()
{
	std::vector<Sales_item> vec;
	std::istream_iterator<Sales_item> init(std::cin), eof;
	
	while(init != eof)
		vec.push_back(*init++);
	std::sort(vec.begin(), vec.end(), compareIsbn);
	
	auto fit = vec.begin(), rfit = vec.begin();
	while(fit != vec.end()) {
		rfit = std::find_if(fit, vec.end(), [fit](Sales_item s1){return s1.isbn() != fit->isbn();});
		std::cout<<std::accumulate(fit, rfit, Sales_item(fit->isbn())) << std::endl;
		fit = rfit;
	}
	
	return 0;
}
