#include<iostream>
int main() {
	int x = 5, y = 10;
	//evaluates the left side, and discards --x, and evaluates --y.
	//if the expression is true, y is incremented back to 10 and x is incremented to 6
	//otherwise both are decremented
	true ? ++x, ++y : --x, --y;
	std::cout<<y<<std::endl;
	std::cout<<x<<std::endl;
	return 0;
}
