#include<vector>
int add(int i, int j)
{
	return i + j;
}
int sub(int i, int j)
{
	return i - j;
}
int mul(int i, int j)
{
	return i * j;
}
int div(int i, int j)
{
	return i/j;
}
int main()
{
	using ifunc = decltype(add);	
	std::vector<ifunc*> v;
	v.push_back(&add);
	v.push_back(&sub);
	v.push_back(&mul);
	v.push_back(&div);
	
	
	return 0;
}
