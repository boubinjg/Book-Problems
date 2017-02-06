#include<iostream>
#include<iomanip>
int main()
{
	std::cout<< std::boolalpha << true << std::noboolalpha << std::endl <<
	std::showbase << 0x16 << std::noshowbase << std::endl <<
	std::showpoint << 10.0 << std::noshowpoint << std::endl <<
	std::showpos << 10 << std::noshowpos << std::endl <<
	std::uppercase << std::hex << 0x10 << std::dec << std::nouppercase << std::endl <<
	std::oct << 0172 << std::dec << std::endl <<
	std::setw(15)<<std::endl << 
	std::left << "asdf" << std::endl <<
	std::right << "asdf" <<std::endl <<
	std::internal << "asdf"<<std::endl <<
	std::fixed << 1.543 << std::endl << std::scientific << 1.1231234124 << std::endl;
	return 0;
}
