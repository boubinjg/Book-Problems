#include<iostream>
//this may never be seen by the compiler, it is handled by the preprocessor.
//This can make error detection difficult 
#define ASPECT_RATION 1.653

const double ar = 1.653; //this should be prefered over the #define

//const strings are preferable to const char*s because creating a constant pointer requires top/bottom
//level const:
const char* const test = "test";

//as compared to a const string:
const std::string test2 = "test2";

class Test{
	//class constants should be static, so there exists only one copy of the constant
	static const int t = 0;
};

//some compilers don't allow the initialization of static variables.
//To avoid this error, you can use an enum
class TestArr{
	enum {num = 3};
	int arr[num];
};

//this confusing and eronious format can be replaced with an inline function
void f(int a) {}
#define CALL_WITH_MAX(a,b) f((a) > (b) ? (a) : (b))

template<typename T>
inline void CallWithMax(const T& a, const T& b) 
{
	f(a>b ? a:b);
}

int main()
{
	return 0;
}
