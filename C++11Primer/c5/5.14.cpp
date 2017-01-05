#include<iostream>
#include<string>
int main()
{
	std::string s, cur = "", max;
	int count = 1, maxCount = 0;
	while(std::cin>>s)
	{
		if(s == cur)
			count++;
		else {
			if(count > maxCount){
				max = cur;
				maxCount = count;
			}
			cur = s;
			count=1;
		}
	}
	std::cout<<max<<" "<<maxCount<<std::endl;
	return 0;
}
