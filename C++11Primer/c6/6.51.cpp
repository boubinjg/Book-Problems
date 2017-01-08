#include<iostream>
void f()
{
	std::cout<<"empty"<<std::endl;
}
void f(int i)
{
	std::cout<<"int"<<std::endl;
}
void f(int i, int j)
{
	std::cout<<"int int"<<std::endl;
}
void f(double i, double j = 3.14)
{
	std::cout<<"double double"<<std::endl;
}
int main()
{
	//f(2.56, 42);
	f(42);
	f(42, 0);
	f(2.56, 3.14);
	return 0;
}
