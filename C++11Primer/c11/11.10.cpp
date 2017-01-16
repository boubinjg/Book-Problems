#include<list>
#include<vector>
#include<map>
int main()
{
	//you can create both of these, but list's bidirectional iterator does not have comparison operators
	//while vector does
	std::map<std::vector<int>::iterator, int> v;
	std::map<std::list<int>::iterator, int> l;
}
