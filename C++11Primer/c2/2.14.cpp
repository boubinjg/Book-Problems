#include<iostream>
int main()
{
	//the program is legal. It prints the outer i (i outside of the loop) which is 100,
	//and sum which is 45
	int i = 100, sum = 0;
	for(int i = 0; i!=10; i++)
		sum += i;
	std::cout<<i<<" "<<sum<<std::endl;
}
