#include<iostream>
std::string change(std::string orig, std::string pref, std::string suf) 
{
	return orig.insert(orig.size(), " "+suf).insert(0, pref + " ");
}
int main()
{
	std::cout<<change("Jayson Boubin", "Mr.", "III")<<std::endl;
	return 0;
}
