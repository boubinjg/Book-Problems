#include<iostream>
int main() 
{
	int sum = 0, val = 1;
	//while this is a more compact statement, I believe this decreases the readability of the code
	//This code may be opaque to an amateur.
	while(sum += val, val < 10)
		++val;
	
	std::cout<<"sum of 1 to 10 inclusive is " 
	         << sum << std::endl;
	return 0;	
}
