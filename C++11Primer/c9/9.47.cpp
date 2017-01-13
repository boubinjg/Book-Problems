#include<string>
#include<iostream>
#include<cctype>
void findForward(std::string s)
{
	std::string digit = "0123456789",  uletter = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::string lletter = "abcdefghijklmnopqrstuvwxyz";
	
	std::string::size_type pos = 0;
	while((pos = s.find_first_of(digit, pos)) != std::string::npos) {
		std::cout<<s[pos]<<std::endl;
		++pos;
	}
	pos = 0;
	while((pos = s.find_first_of(uletter + lletter, pos)) != std::string::npos) { 
		std::cout<<s[pos]<<std::endl;
		++pos;
	}	
}
void findBack(std::string s)
{
	std::string digit = "0123456789",  uletter = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::string lletter = "abcdefghijklmnopqrstuvwxyz";
	
	std::string::size_type pos = s.size();
	while((pos = s.find_last_of(digit, pos)) != std::string::npos) {
		std::cout<<s[pos]<<std::endl;
		--pos;
	}
	pos = s.size();
	while((pos = s.find_last_of(uletter + lletter, pos)) != std::string::npos) { 
		std::cout<<s[pos]<<std::endl;
		--pos;
		if(pos == std::string::npos)
			break;
	}	
}
int main()
{
	findForward("ab2c3d7R4E6");
	findBack("ab2c3d7R4E6");

	return 0;
}
