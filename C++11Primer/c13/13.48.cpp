#include"13.47.h"
#include<vector>
int main()
{
	String s0;
	String s1("hello");
	String s2(s0);
	String s3 = s1;
	std::vector<String> v;
	v.push_back(s0);
	v.push_back(s1);
	v.push_back(s2);
	v.push_back(s3);
	return 0;
}
