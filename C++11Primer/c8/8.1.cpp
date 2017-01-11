#include<iostream>
std::istream& read(std::istream& io)
{
	char c;
	while(io>>c)
	{
		std::cout<<c<<std::endl;
	}
	io.clear();
	return io;
}
int main()
{
	read(std::cin);
	return 0;
}
