#include<iostream>
int main()
{
	char* c = new char[100];
	char in;
	int i = 0;
	while(std::cin>>in) {
		c[i] = in;
		i++;
		if(i == 99)
			break;
	}
	c[i] = '\0';
	std::cout<<c<<std::endl;
}
