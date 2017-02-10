class A{
public:
	A() = default;
};
class B : public A{
public:	
	B() : A() {}
};
class C : public B{
public:
	C() : B() {}
};
class X{
public:
	X() = default;
};
class Y{
public:
	Y() = default;
};
class Z : public X, public Y{
public:
	Z() : X() , Y() {}
};
class MI : public C, public Z{
public:
	MI() : C(), Z(){}
};
class D : public X, public C{
	D() : X(), C() {

	}
};

/*
a) legal
b) legal
c) legal
d) legal
*/
