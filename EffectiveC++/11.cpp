//handle assignment to self in operator=.

//assignment to self happens often with aliasing.

class Widget{
	int *pb;
	/* This version of the widget assignment operator is not safe,
	 * if rhs and this are the same, we would delete pb, then use pb
	Widget& operator=(const Widget& rhs) {
		delete pb;
		pb = new int(*rhs.pb);
		return *this;
	}*/

	/* This version "works" but can still cause exceptions.
	 * if the int construction throws an exception, pb will be undefined.
	 * we can do better
	Widget& operator=(const Widget& rhs) {
		if(&rhs == this) return *this;
		delete pb;
		pb = new int(*rhs.pb);
		return *this;
	}*/
	//Here, if int throws an exception, pb remains unchanged. 
	Widget& operator=(const Widget& rhs) {
		int *pOrig = pb;
		pb = new int(*rhs.pb);
		delete pOrig;
		return *this;
	}
};

int main()
{
	return 0;
}
