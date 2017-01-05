#include<iostream>
#include<cctype>
int main()
{
	int count = 0;
	std::string s;
	while(std::getline(std::cin, s))
	{
		bool prevf = false;
		for(auto &c : s)
		{
			switch(std::tolower(c))
			{
				case 'a':
				case 'e':
				case 'i':
				case 'o':
				case 'u':
				case '\t':
				case ' ':
				case '\n':
					count++;
					break;
			}
		}
	}
	std::cout<<count<<std::endl;
	return 0;
}
