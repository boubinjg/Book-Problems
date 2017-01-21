#include<iostream>
static int b = 0;
class numbered {
public:
	int mysn;
	numbered() : mysn(++b){}
};
void f(numbered s) {std::cout<<s.mysn<<std::endl;}

class numberedCop {
public:
	int mysn;
	numberedCop() : mysn(b+1){}
	numberedCop(numberedCop &n){
		mysn = ++b;
	}
};
void f(numberedCop s) {std::cout<<s.mysn<<std::endl;}

class numberedConst {
public:
	int mysn;
	numberedConst() : mysn(b+1){}
	numberedConst(const numberedConst &n){
		mysn = ++b;
	}
};
void f(numberedConst s) {std::cout<<s.mysn<<std::endl;}



int main()
{
	numbered a, b = a, c = b;
	f(a); f(b); f(c);
	
	numberedCop a2, b2 = a2, c2 = b2;
	f(a2); f(b2); f(c2);	
	
	numberedConst a3, b3 = a3, c3 = b3;
	f(a3); f(b3); f(c3);
}
