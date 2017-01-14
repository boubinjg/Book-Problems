#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<exception>
class date{
private:
	unsigned day, month, year;
public:	
	date() : day(0),month(0),year(0) {}
	date(std::string s);
};
date::date(std::string s) {
	// 1/1/1111
	std::vector<std::string> smonths{"jan", "feb", "mar", "apr", "may", "jun", 
				         "jul", "aug", "sep", "oct", "nov", "dec"};
	std::vector<std::string> months{"january","february","march","april",
					"may","june","july","august",
					"september","october","november","december"};
	auto pos = 0;
	std::string smonth;
	
        try{
 		if((pos = s.find("/")) != std::string::npos) {
			month = stoi(s.substr(0,pos));
			auto npos = s.find("/", pos+1);
			day = stoi(s.substr(pos+1, npos));
			year = stoi(s.substr(npos+1));
		}
		if((pos = s.find(" ")) != std::string::npos) {
			smonth = s.substr(0, pos);
			auto npos = s.find(",");
			day = std::stoi(s.substr(pos+1, npos));
			year = std::stoi(s.substr(npos+1));
			auto mv = std::find(smonths.begin(), smonths.end(), smonth);
			if(mv != smonths.end() ) {
				month = mv - smonths.begin() + 1;
			}
			else{
				mv = std::find(months.begin(), months.end(), smonth);
				month = mv - months.begin() + 1;
			}
		}
		std::cout<<month<<" "<<day<<" "<<year<<std::endl;
        } catch(std::exception e) {
		std::cout<<"incorrect format"<<std::endl;
	}
}
int main()
{
	date d("1/1/1111");
	date e("jan 1, 1000");
	date f("september 16, 1994");
	date g("asdf asdf asdf");
}
