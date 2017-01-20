#include<iostream>
static int b = 0;
class numbered {
public:
	int mysn;
	numbered() : mysn(b+1){}
};
void f(numbered s) {std::cout<<s.mysn<<std::endl;}

class numberedCop {
public:
	int mysn;
	numberedCop() : mysn(b+1){}
	numberCop(numberedCop &n){
		n.mysn = 0;
	}
};
void f(numberedCop s) {std::cout<<s.mysn<<std::endl;}

int main()
{
	numbered a, b = a, c = b;
	f(a); f(b); f(c);
	

}
