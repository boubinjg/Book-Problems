#include<iostream>
int main()
{
	char c;
	int count = 0;
	while(std::cin>>c)
	{
		if(c == 'a')
			count++;
		else if(c == 'e')
			count++;
		else if(c == 'i')
			count++;
		else if(c == 'o')
			count++;
		else if(c == 'u')
			count++;	
	}
	std::cout<<count<<std::endl;
	return 0;
}
