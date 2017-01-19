#include"12.30.h"
int main()
{
	std::ifstream in("12.27.txt");
	TextQuery t(in);
	QueryResult q = t.query("stuff");
	print(std::cout, q);
	return 0;
}
