#include<iostream>
#include<string>
class c{
public:
	int mem;
};
void swap(c v1, c v2)
{
	using std::swap;
	swap(v1, v2);
}
int main()
{
	c c1, c2;
	c1.mem = 1;
	c2.mem = 2;
	swap(c1, c2);
	return 0;
}
