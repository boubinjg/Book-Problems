class A{
public:
 	A() = default;
	virtual ~A() {}
};
class B : public A {	
public:
	B() : A() {}
	virtual ~B() override {}
};
class C : public B {
public:
	C() : B() {}
	virtual ~C() override {}
};

int main()
{
	A *pa = new C;
	if (C *p = dynamic_cast<C*>(pa)) {
		C& ret = dynamic_cast<C&>(*pa);	
	} else {

	}
}
