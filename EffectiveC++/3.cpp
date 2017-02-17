#include<vector>
#include<string>

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

//bitwise const: can't modify any of the physical bits
//doesnt check whether 

//logical const: const functions may modify bits of its data members, but only in ways 
//that clients can not detect.

class T{
	mutable int i; //an int that is always modifiable regardless of constness of functions
};

//Note: Usually using casts should be avoided (item 27)
class noCodeReuse{
	const char text[];
	const char& operator[](const std::size_t position) const
	{
		/*
			do all of the things either the const or nonconst would both do
		*/
		return text[position];	
	}
	char& operator[](const std::size_t position)
	{
		//this casts to const to call the const version of the [] operator
		//then casts the result to a non-const char& because the function doesn't
		//return const.
		return const_cast<char&>(static_cast<const noCodeReuse&>(*this)[position]);
	}
};

//important notes:
	//declaring something const helps protect against usage errors
	//compilers = bitwise const, we must support logical const
	//avoid code duplication by having non-const functions call their own const versions.

int main()
{
	return 0;
}                                                      
