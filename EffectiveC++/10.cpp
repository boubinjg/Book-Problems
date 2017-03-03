//have assignment operators return a reference to *this
class Widget {
public:	
	Widget& operator=(const Widget& rhs) {
		*this = rhs;
		return *this;
	}
};
int main()
{
	//by returning a reference to *this, we can chain the = operator. We can do this
	//with other operators as well such as +=
	Widget w, x, y;
	w = x = y = Widget();
	return 0;
}
