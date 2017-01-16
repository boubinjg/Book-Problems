#include<map>
#include<iostream>
int main()
{
	std::map<int, int> word_count;
	std::map<int, int>::const_iterator map_it = word_count.cbegin();
	while(map_it != word_count.cend()) {
		std::cout<<map_it->first<<" "<<map_it->second<<std::endl;
		++map_it;
	}
}
