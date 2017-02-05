#include<bitset>
#include<iostream>
#include<string>
int main()
{
	std::string bstr;
	std::cin>>bstr;
	std::bitset<8> bv(bstr);
	std::cout<<bv.to_string()<<std::endl;
	return 0;
}
