#include<iostream>
#include<map>
#include<string>

int main()
{
	std::multimap<std::string, std::string> authors;
	authors.insert({"asdf","efgh"});
	authors.insert({"asdf","gg"});
	authors.insert({"ffds","tetd"});
	authors.insert({"bb", "as"});
	
	for(auto p : authors)
		std::cout<<p.first<<" "<<p.second<<std::endl;
	
	return 0;
}
