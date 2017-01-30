#include<iostream>
#include<vector>
#include<list>
template <typename t, typename u>
int find(const t& col, const u& val)
{
	int count= 0;
	for(auto it = col.begin(); it!=col.end(); it++) {
		if(*it == val) 
			return count;
		++count;
	}
	return -1;
}
int main()
{
	std::list<std::string> l{"asdf", "fdfds", "gg"};
	std::vector<int> v{1,2,5,6,3};
	std::cout<<find(v, 5)<<" "
	<<find(l, "asdf")<<std::endl;
	return 0;
}
