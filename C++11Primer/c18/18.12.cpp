#include"18.12.h"
int main()
{
	std::ifstream in("18.12.txt");
	chapt18::TextQuery t(in);
	chapt18::QueryResult q = t.query("stuff");
	print(std::cout, q);
	return 0;
}
