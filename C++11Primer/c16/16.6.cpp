#include<iostream>
template<typename t, unsigned sz>
t* begin(t (&arr)[sz])
{
	return arr;
}
template<typename t, unsigned sz>
t* end(t (&arr)[sz])
{
	return arr + sz;
}
int main()
{
	int i[] = {1,2,3,4,5};
	std::cout<<*(end(i)-1)<<" "<<*(begin(i))<<std::endl;
}
