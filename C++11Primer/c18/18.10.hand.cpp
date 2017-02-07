#include"14.2.h"
int main()
{
	Sales_data s1("asdf"), s2("asdff");
	try {
		s1 += s2;
	} catch(isbn_mismatch m) {
		std::cout<<"handled"<<std::endl;
	}

	return 0;
}
