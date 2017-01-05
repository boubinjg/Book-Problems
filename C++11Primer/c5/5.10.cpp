#include<iostream>
#include<cctype>
int main()
{
	int count = 0;
	char c;
	std::string s;
	while(std::cin>>c)
	{
		switch(std::tolower(c))
		{
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				count++;
				break;
		}
		
	}
	std::cout<<count<<std::endl;
	return 0;
}
