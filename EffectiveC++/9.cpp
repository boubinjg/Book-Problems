//Never call virtual functions during construction or destruction

class a {
public:
	a() {virt();}
	virtual void virt();
};
class b : public a {
public:
	virtual void virt();
};
class c : public a {
public:
	virtual void virt();
};
//When creating a b object or c object, the constructor for a is called. The constructor for a
//will always call the virt function in a, never for its derived classes.

//this is because the derived objects which would be called havn't been constructed.
//When constructing a derived object, its internal base object must be initialized first.

//this is the same durring destruction.

/* fix: 
	use non virtual functions for each class and properly call base constructors
	from derived constructors.
*/

int main()
{
	return 0;
}
