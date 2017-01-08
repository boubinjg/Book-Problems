
#include<vector>
int func(int i, int j);

int main()
{
	using ifunc = int(int i, int j);
	using ifunc2 = decltype(func);	
	std::vector<ifunc*> v;
	std::vector<ifunc2*> v2;
	v = v2;
	return 0;
}
