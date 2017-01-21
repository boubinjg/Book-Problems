#include"13.30.h"
#include<vector>
#include<algorithm>
int main()
{
	std::vector<HasPtr> hp;
	hp.push_back(HasPtr("sasdf"));
	hp.push_back(HasPtr("fdfd"));
	hp.push_back(HasPtr("asdf"));
	hp.push_back(HasPtr("ddfd"));
	
	std::sort(hp.begin(), hp.end());

	return 0;
}
