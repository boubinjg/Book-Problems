
#include<string> 
#include<iostream>
#include<memory>
int main()
{
	int n = 10;
	std::allocator<std::string> alloc;
	auto p = alloc.allocate(n);
	std::string s;
	auto q = p;
	while(q != p + n && std::cin>>s) {
		alloc.construct(q, s);
		++q;
	}
	while(p != q)		
		alloc.destroy(--q);
	alloc.deallocate(p, n);
	return 0;
}
