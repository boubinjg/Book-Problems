#include<iostream>
int main() {
	int x[10];
	int *p = x;
	
	//prints 10
	std::cout <<sizeof(x)/sizeof(*x)<<std::endl;
	//prints 1
	std::cout <<sizeof(p)/sizeof(*p)<<std::endl;
	
	//my predictions were close. the first expression does print 10. The second prints 2
	//I assume that 8 bytes are required to p, and only 4 to hold *p
	return 0;
}
