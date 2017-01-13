#include<forward_list>
#include<iostream>
int main()
{
	std::forward_list<int> f{1,2,3,4,5};
	auto it = f.before_begin();
	auto cur = f.begin();

	while(cur != f.end()) {
		if(*cur % 2)
			cur = f.erase_after(it);
		else {
			cur++;
			it++;
		}
	}
	for(auto i : f)
		std::cout<<i<<std::endl;
}
