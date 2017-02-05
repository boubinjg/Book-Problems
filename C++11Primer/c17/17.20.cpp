#include<regex>
#include<string>
#include<iostream>
bool valid(const std::smatch& m)
{
	if(m[1].matched) {
		return m[3].matched && 
		       (m[4].matched == 0 || m[4].str() == " ");
	} else {
		return !m[3].matched &&
		       m[4].str() == m[6].str();
	}
}
int main()
{
	std::string phone = "(\\()?(\\d{3})(\\))?([-.[:space:]+])?(\\d{3})([-.[:space:]+]?)(\\d{4})";
	std::regex r(phone);
	std::smatch m;
	std::string s;
	
	while(getline(std::cin, s, '\n')) {
		for(std::sregex_iterator it(s.begin(), s.end(), r), endit; 
		    it != endit; ++it)
		{
			if(valid(*it))
				std::cout<<"valid: "<<it->str()<<std::endl;
			else
				std::cout<<"invalid: "<<it->str()<<std::endl;	
		}
	}

	return 0;
}
