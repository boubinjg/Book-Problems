#include<iostream>
void print1(const int *i)
{
	if(i)
		while(*i)
			std::cout<<*i++;
}
void print2(const int *beg, const int *end)
{
	while(beg != end)
		std::cout<<*beg++<<std::endl;
}
void print3(const int ia[], size_t size)
{
	for(size_t i = 0; i!=size; i++)
		std::cout<<ia[i]<<std::endl;
}
int main()
{
	int i = 0, j[2] = {0,1};

	//print1(j);legal but doesnt work
	//print1(i);illegal

	print2(std::begin(j),std::end(j));//great
	//print2(std::begin(i),std::end(i));illega

	print3(j, 2);//great
	//print3(i, 1);illegal
	return 0;
}
