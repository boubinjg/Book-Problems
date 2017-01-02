#include<iostream>
int textsize()
{
	return 5;
}
int main()
{
	unsigned buff_size = 1024;
	int ia[buff_size];//legal
	int ia2[4*7-14];//legal
	int ia3[textsize()];//legal
	//char st[11] = "fundamental";//illegal
}
