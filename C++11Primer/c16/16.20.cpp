#include<vector>
#include<iostream>
template <typename T>
void print(T& con)
{	
	for(auto i = con.begin(); i!=con.end(); i++)
		std::cout<<*i<<std::endl;	
}
int main()
{
	std::vector<int> v{1,2,3,4,5};
	print(v);
	return 0;
}
