#include<iostream>
#include<fstream>
int main()
{
	std::ifstream f("17.37.txt");
	char i[10];
	while(f.getline(i, 10, '\n')){
		std::cout.write(i, 10);
		std::cout.put('\n');
	}
	return 0;
}
