class empty{
	//the compiler will synthesize constructors and a destructor if not provided
public:
	
	inline empty(){}
	inline empty(const empty& e){}
	inline empty& operator=(const empty& rhs){}
	inline ~empty();
};
//they are only generated if they are needed

//compilers won't synthesize these functions if you provide them yourself

//synthesized copy functions perform member-wise copy where applicable

//if you want to copy const members or references, you will have to define your own
//copy functions

//you must also define your own copy members in derived classes.
int main()
{
	return 0;
}
