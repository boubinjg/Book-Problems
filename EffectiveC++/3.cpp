#include<vector>

char greeting[] = "hello";
char *p = greeting; //non-const pointer, non-const data
const char *p2 = greeting; //non-const pointer, const data
char * const p3 = greeting; //const pointer non-const data
const char * const p4 = greeting; //const pointer const data

//const iterators:
std::vector<int> v;
std::vector<int>::const_iterator c = v.cbegin();

//If a function returns a const value, it can not be used for assignment. This can help
//cut down on runtime errors produced by typos

//unless you need to modify parameters passed to a function, the parameters should be const.

/* C++ functions can be overloaded simply based on the constness of
   their parameters. This is important because we can make seperate
   functions for const and nonconst objects. This will provide certain functionalities
   to only non-const objects. Ex: the TextBlock class on pg. 20
*/


int main()
{
	return 0;
}                                                      
