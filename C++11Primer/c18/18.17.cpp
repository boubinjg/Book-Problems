namespace Exercise {
	int ivar = 0;
	double dvar = 0;
	const int limit = 1000;
}
int ivar = 0;
//position one
void manip() {
	//position two
	using Exercise::ivar;
	using Exercise::limit;
	
	double dvar = 3.1416;
	int iobj = limit + 1;
	//++ivar;
	++::ivar;
}
int main()
{
	manip();
	return 0;	
}
