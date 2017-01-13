#include<list>
#include<iostream>
#include<forward_list>
int main()
{
	std::list<int> l{1,2,3,4,5,6};
	auto iter = l.begin();
	while(iter != l.end()) {
		if(*iter % 2) {
			iter = l.insert(iter,*iter);
			//list doesnt support +=
			++++iter;
		} else 
			iter = l.erase(iter);
	}
	for(auto i : l)
		std::cout<<i<<std::endl;


	std::forward_list<int> f{1,2,3,4,5,6};
	
	auto fiter = f.begin();
	auto bit = f.before_begin();
	while(fiter != f.end()) {
		if(*fiter % 2) {
			fiter = f.insert_after(fiter,*fiter);
			++++fiter;
		} else {
			fiter = f.erase_after(fiter);
			
		}
	}
	for(auto i : l)
		std::cout<<i<<std::endl;

	return 0;
}
