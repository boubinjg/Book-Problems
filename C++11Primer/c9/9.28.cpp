#include<string>
#include<forward_list>
#include<iostream>
void doit(std::forward_list<std::string>& f, std::string s1, std::string s2)
{
	auto cur = f.begin();
	while(cur != f.end())
	{
		if(*cur == s1) {
			f.insert_after(cur, s2);
			return;
		}
		cur++;
	}
	f.insert_after(cur, s2);
}
int main()
{
	std::forward_list<std::string> f{"asdf", "fdas", "ff"};
	doit(f, "ff","hello");

	for(auto s : f)
		std::cout<<s<<std::endl;
	return 0;
}
