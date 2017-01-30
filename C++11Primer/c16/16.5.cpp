#include<iostream>
template<typename s>
void print(const s &arr)
{
	for(auto i : arr)
		std::cout<<i<<std::endl;
}
int main()
{
	int i[5] = {1,2,3,4,5};
	print(i);
	return 0;
}
