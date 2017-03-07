//prefer pass by reference to const to pass by value
#include<string>

class a{
private:
	std::string str1, str2;
};
class b : public a {
private:
	std::string str3, str4;
public:
	b() : a() {}
};
//passing a b object by value requires 12 operations, 6 constructions (a, b, 4 strings) and 6
//destructions of the same types.

//passing by reference to const both requires the object must not be modified, and that
//the object will not call these constructors/destructors, Thus behaving exactly like a 
//pass by value, but more efficient.

//passing by reference to const also avoids the slicing problem
//if a b value were passed as an a, the a constructor would be called to copy it, instead
//of the b value, we would only have the a part of the b value. Passing by reference avoids this.

//references are often handled by the compiler as pointers. Because of this, it is often more 
//efficient to pass built-in types by value. This is the same for iterators and STL function objects.

//the above advice obviously does not apply to containers. STL containers should be passed by reference.

int main()
{
	return 0;
}
