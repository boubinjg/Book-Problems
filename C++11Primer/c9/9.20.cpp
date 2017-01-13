#include<iostream>
#include<deque>
#include<list>
int main()
{
	std::list<int> l{1,2,3,4,5,6,7,8,9};
	std::deque<int> even, odd;
	for(auto i : l) {
		if(i%2)
			odd.push_back(i);
		else
			even.push_back(i);
	}

	for(auto i : even)
		std::cout<<i<<std::endl;
	for(auto i : odd)
		std::cout<<i<<std::endl;
	return 0;
}
