class base{};
class pub : public base{
public:
	void memfcn(base &b) {b = *this;}
};
class prot : protected base{
public:	
	void memfcn(base &b) {b = *this;}
};
class priv : private base{
public:	
	void memfcn(base &b) {b = *this;}
};
class dpub : public pub {};
class dprot : public prot {};
class dpriv : public priv {};

int main()
{
	pub d1;
	priv d2;
	prot d3;
	dpub dd1;
	dpriv dd2;
	dprot dd3;

	base *p = &d1;
	//p = &d2;
	//p = &d3;
	p = &dd1;
	//p = &dd2;
	//p = &dd3;	

	base b;
	d1.memfcn(b);
	d2.memfcn(b);
	d3.memfcn(b);

	return 0;
}
