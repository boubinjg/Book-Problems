#include"13.53.h"
int main()
{
	HasPtr p0("asdf");
	HasPtr p1(p0);
	HasPtr p2 = p1;
	HasPtr p3 = std::move(p1);
	return 0;
}
