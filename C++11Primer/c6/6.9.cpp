#include"6.8.h"
int fact(int i)
{
	int ret = 1;
	while(i>1)
		ret *= i--;
	return ret;
}
