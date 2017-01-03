#include<iostream>
int main()
{
	//-86
	int i1 = -30 * 3 + 21 / 5;
	//-18
	int i2 = -30 + 3 * 21 / 5;
	//0
	int i3 = 30 / 3 * 21 % 5;
	//-2
	int i4 = -30 / 3 * 21 % 4;
	std::cout<<i1<<" "<<i2<<" "<<i3<<" "<<i4<<std::endl;
	return 0;
}
