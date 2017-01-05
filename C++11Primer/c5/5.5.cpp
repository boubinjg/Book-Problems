#include<iostream>
#include<vector>
#include<string>
int main()
{
	std::vector<std::string> s = {"F", "D", "C", "B", "A", "++A"};
	int score = 100;
	if(score < 60)
		std::cout<<s[0]<<std::endl;
	else
	{
		std::cout<<s[(score-50)/10]<<std::endl;
	}
	return 0;
}
