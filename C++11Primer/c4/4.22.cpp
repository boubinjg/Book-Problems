#include<iostream>
#include<string>
int main() {
	
	unsigned grade = 62;
	std::string finalgrade;

	finalgrade = (grade > 90) ? "high pass" :
			          (grade < 60) ? "fail" : 
					       (grade <75) ? "low pass" : "pass";

	std::cout<<finalgrade<<std::endl;
	return 0;	
}
