#include<functional>
#include<map>
#include<iostream>
#include<string>
class multiply{
public:
	int operator()(int i, int j) {
		return i * j;
	}
};
class divide{
public:
	int operator()(int i, int j) {
		return i/j;
	}
};
int sub(int i, int j)
{
	return i - j;
}
int main()
{
	std::map<std::string, std::function<int(int, int)>> calc;
	multiply mul;	
	calc["*"] = mul;
	divide div;
	calc["/"] = div;
	calc["+"] = [](int i, int j){return i + j;};
	calc["-"] = sub;
	std::cout<<calc["*"](2,3)<<std::endl;
	std::cout<<calc["/"](10, 2)<<std::endl;
	std::cout<<calc["+"](2, 5)<<std::endl;
	std::cout<<calc["-"](20, 14)<<std::endl;
}
