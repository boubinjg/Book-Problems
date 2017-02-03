#include<utility>
#include<iostream>
void f(int v1, int& v2)
{
	std::cout<<v1<<" "<<++v2<<std::endl;
}
template <typename F, typename T1, typename T2>
void flip1(F f, T1 &&t1, T2 &&t2)
{
	f(std::forward<T2>(t2), std::forward<T1>(t1));
}
template <typename F, typename T1, typename T2>
void flip2(F f, T1 t1, T2 t2)
{
	f(t2, t1);
}
int main()
{
	int i = 42;
	flip2(f,i, 0);
	flip1(f,i, 0);
	std::cout<<i<<std::endl;
	return 0;
}
