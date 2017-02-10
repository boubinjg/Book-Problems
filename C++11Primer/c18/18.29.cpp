class Class {};
class Base : public Class {};
class D1 : virtual public Base {};
class D2 : virtual public Base {};
class MI : public D1, public D2 {};
class Final : public MI, public Class {};

int main()
{
	Base *pb;
	Class *pc;
	MI *pmi;
	D2 *pd2;
	
	//pb = new Class; no conversion (class is derived from base)
	//pc = new Final; ambiguous
	//pmi = pb; no conversion (same as above)
	pd2 = pmi;
	return 0;
}
