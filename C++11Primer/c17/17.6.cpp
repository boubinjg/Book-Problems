#include<string>
#include<vector>
#include<tuple>
#include<algorithm>
#include"Sales_data.h"
#include<iostream>
struct retVal{
	std::vector<Sales_data>::size_type sz;
	std::vector<Sales_data>::const_iterator beg, end;	
};
bool compareIsbn(Sales_data d1, Sales_data d2)
{
	return d1.isbn() < d2.isbn();
}
typedef std::tuple<std::vector<Sales_data>::size_type,
		   std::vector<Sales_data>::const_iterator,
		   std::vector<Sales_data>::const_iterator> matches;

std::vector<retVal>
findBook(const std::vector<std::vector<Sales_data>> &files,
	 const std::string &book)
{
	std::vector<retVal> ret;
	for(auto it = files.cbegin(); it != files.cend(); ++it)
	{
		auto found = std::equal_range(it->cbegin(), it->cend(),
			 		      book, compareIsbn);
		if(found.first != found.second) {
			retVal r;
			r.sz = it-files.cbegin();
			r.beg = found.first;
			r.end = found.second;	
			ret.push_back(r);
		}
	}
	return ret;
}

int main()
{
	return 0;
}
