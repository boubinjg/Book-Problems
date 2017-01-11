class NoDefault
{
public:	
	NoDefault(int i);
};
class c
{
	NoDefault d;
	c() : d(0) {}
};
