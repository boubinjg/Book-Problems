#include<vector>
#include<iostream>
//make sure objects are initialized before use

//It is good to assume that things which existed in c are not initialized by default
//and that c++ constructs are. for example:

//good to assume this array is not default initialized
int i[5];
//the vector should be default initialzed
std::vector<int> iv;

//initialize c constructs before use:

int a = 0;
double d;
const char* c = "asdgb";

//c++ constructs depend on construcors

//data members of classes are initialized before the body of their constructor
class test{
	int a;
	double b;
	char c;
	std::vector<int> v;
	//                                 initialization list: more efficient
	test(int ti, double td, char tc, std::vector<int> tv) : a(ti), b(td), c(tc), v(tv)
	{
		//assignment: this is more work
		a = ti;
		b = td;
		c = tc;
		//if this wasn't initialized before the costructor body, its default constructor
		//would be called, and it would have been assigned tv.
		v = tv;
	}
};

//const/reference data members must be initialized, so you must use an initialization list

//base class objects are always initialized before derived objects
//members are initialized in the order in which they are declared.

//if a non-local static object (object in global scope/with the static specifier...) uses another object
//which is non-local static from another "translation unit" (another file), the object its using to initialize
//itself could be uninitialized. results in UB

//the relative initialization of non-local static objects in different translation units is undefined, so you can't
//know which will be initialized first.

// the above problem can be solved by declaring these objects as local static objects (local to a function)
// which makes them singletons. These objects are first initialized (based on the standard) when the function
// is called, guaranteeing that they will be initialized when being used to initialize other objects.

//these singleton patterns are also good for inlining (see page 32).

int main()
{
	//d is initialized here
	std::cin>>d;
	return 0;
}
