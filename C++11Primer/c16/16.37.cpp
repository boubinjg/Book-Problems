#include<iostream>
#include<algorithm>
int main()
{
	int i = 0;
	double d = 0.0;
	//must add the template argument
	int r = std::max<int>(i, d);
	return 0;
}
