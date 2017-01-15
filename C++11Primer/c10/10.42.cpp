#include<iostream>
#include<list>
#include<iterator>
int main()
{
	std::list<int> l{1,1,2,2,3,3,4,4,5,6};
	l.unique();
	std::ostream_iterator<int> os(std::cout, " ");
	std::copy(l.begin(), l.end(), os);
	std::cout<<std::endl;
	return 0;
}
