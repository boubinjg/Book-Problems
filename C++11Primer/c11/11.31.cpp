#include<iostream>
#include<map>
#include<string>

int main()
{
	std::multimap<std::string, std::string> authors;
	authors.insert({"asdf","efgh"});
	authors.insert({"asdf","gg"});
	authors.insert({"ffds","tetd"});
	
	std::string work = "gg";
	for(auto it = authors.equal_range("asdf");
	    it.first != it.second; ++it.first) {
		if(it.first->second == work)
			it.first = authors.erase(it.first);
	}
	
	for(auto p : authors)
		std::cout<<p.first<<" "<<p.second<<std::endl;
	
	return 0;
}
