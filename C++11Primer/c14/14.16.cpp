#include"14.16.string.h"
#include"14.16.strblob.h"
#include"14.16.strvec.h"
int main()
{
	String s("abcd");
	String s2("abcd");
	String s3("abc");
	std::cout<<(s == s2)<<(s2 == s3)<<std::endl;
	std::string str = "abc", str2 = "abcd";
	StrBlob st1({str}); 
	StrBlob st2({str});
	StrBlob st3({str2});
	std::cout<<(st1 == st2)<<(st2 == st3)<<std::endl;
	
	StrVec v1;
	v1.push_back(str);
	StrVec v2; 
	v2.push_back(str);
	std::cout<<(v1 == v2);
	StrVec v3;
	v3.push_back(str2);
	std::cout<<(v2 == v3)<<std::endl;
	return 0;
}
