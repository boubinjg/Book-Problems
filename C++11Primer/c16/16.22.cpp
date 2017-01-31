#include"16.22.h"
int main()
{
	std::ifstream in("16.22.txt");
	TextQuery t(in);
	QueryResult q = t.query("stuff");
	print(std::cout, q);
	return 0;
}
