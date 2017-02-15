#include<iostream>
#include<string>
#include<algorithm>
int main()
{
	std::string s1 = "abcdefg", s2 = "bcdefg";
	//returns true if the first sequence is lexicographically less than the second
	bool b = std::lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end());
	std::cout<<std::boolalpha<<b<<std::endl;
	return 0;
}
