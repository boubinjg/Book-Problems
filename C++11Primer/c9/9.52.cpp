#include<stack>
#include<iostream>
#include<string>
int main()
{
	std::stack<int> stack;
	int level = 0;
	std::string s = "((a))(b(())(d))()e()((c(())())())";
	for(auto c : s) {
		if(c == '(') {
			stack.push(++level);
			std::cout<<"going to level "<<level<<std::endl;
		}
		else if(c == ')') {
			if(stack.empty()) {
				throw "woah there";
			}
			else
			{
				std::cout<<"going up to level "<<--level<<std::endl;
				stack.pop();
			}
		}
	}
	if(level) {
		throw "oh no you dont!";
	}
	return 0;
}
