#include<vector>
#include<iostream>
template <typename T>
void print(T& con)
{	
	for(typename T::size_type i = 0; i<con.size(); i++)
		std::cout<<con[i]<<std::endl;	
}
int main()
{
	std::vector<int> v{1,2,3,4,5};
	print(v);
	return 0;
}
