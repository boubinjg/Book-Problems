#include<bitset>
#include<iostream>
int main()
{
	int i = 1, j = 1, last = 0;
	std::bitset<22> b;
	while(i <=21) {
		last = i;
		b.set(i);
		i += j;
		j = last;
	}
	std::cout<<b<<std::endl;
	return 0;
}
