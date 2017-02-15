#include<iostream>
#include<algorithm>
#include<vector>
#include<random>
int main()
{
	std::string s = "0123456789", s2 = "0987654321";

	//determines if two ranges are permutations, also takes a predicate
	bool b = std::is_permutation(s.begin(), s.end(), s2.begin());
	std::cout<<std::boolalpha<<b<<std::endl;
	
	std::next_permutation(s.begin(), s.end());
	std::cout<<s<<std::endl;
	
	std::prev_permutation(s.begin(), s.end());
	std::cout<<s<<std::endl;	

	return 0;
}
