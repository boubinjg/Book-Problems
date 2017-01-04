#include<iostream>
int main() {
	unsigned long ul1 = 3, ul2 = 7;
	//prints 3
	std::cout<< (ul1 & ul2) <<std::endl;
	//prints 7
	std::cout<< (ul1 | ul2) <<std::endl;
	//returns true, so prints 1
	std::cout<< (ul1 && ul2) <<std::endl;
	//returns true, so prints 1
	std::cout<< (ul1 || ul2) <<std::endl;
	return 0;
}
