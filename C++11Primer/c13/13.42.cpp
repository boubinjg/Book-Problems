#include"13.42.h"
int main()
{
	std::ifstream in("13.42.txt");
	TextQuery t(in);
	QueryResult q = t.query("stuff");
	print(std::cout, q);
	return 0;
}
