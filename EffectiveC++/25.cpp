//consider support for non-throw swap

//somes the default swap can be slow for certain objects, so it may be best
//to implement it yourself.
#include<algorithm>
class aimpl{
	
};
class a{
public:
	void swap(a &other)
	{
		using std::swap;
		swap(ap, other.ap);
	}
private:
	aimpl *ap;
};

//say we wanted to swap two a objects. We would only need to swap the ap pointers, not the entire
//object. We would rewrite swap
namespace std{

	template<>
	void swap<a>(a& one, a& two)
	{
		one.swap(two);
	}
}

//if we need to swap a template class, we can not simply create a swap function as above.
//we would need to create a version of swap that is not a specialized version of std::swap
//which is a non-member which calls the member swap, because of stl template rules.

//also make sure swap never throws an exception

int main()
{
	return 0;
}
