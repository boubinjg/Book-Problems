#include"16.62.h"
#include<unordered_set>
int main()
{
	Sales_data s1("asdf", 5, 6);
	Sales_data s2("asdf", 5, 6);
	Sales_data s3;

	std::unordered_multiset<Sales_data> s;
	s.insert(s1);
	s.insert(s2);
	s.insert(s3);

	for(auto i : s)
		std::cout<<i<<std::endl;
}
