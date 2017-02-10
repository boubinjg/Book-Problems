class Class {
public:

};
class Base : public Class {
public:
	Base() = default;
	Base(const Base &b) {
		*this = b;
	}
	Base(int i){}

};
class D1 : virtual public Base {
public:
	D1() = default;
	D1(const D1 &d1) : Base(d1) {
		*this = d1;
	}
	D1(int i) : Base(i) {}
};
class D2 : virtual public Base {
public:
	D2() = default;
	D2(const D2 &d2) : Base(d2) {
		*this = d2;
	}
	D2(int i) : Base(i) {}

};
class MI : public D1, public D2 {
public:
	MI() = default;
	MI(const MI &mi) : Base(mi), D1(mi), D2(mi) {
		*this = mi;
	}
	MI(int i) : Base(i), D1(i), D2(i) {}

};
class Final : public MI, public Class {
public:
	Final() = default;
	Final(const Final &f) : MI(f) {
		*this = f;
	}
	Final(int i) : MI(i) {}

};

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
