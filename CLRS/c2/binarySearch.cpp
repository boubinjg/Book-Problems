#include<iostream>
#include<vector>
template <typename T>
void print(const std::vector<T>& v)
{
	for(auto i : v)
		std::cout<<i<<" ";
	std::cout<<std::endl;
}

template <typename T>
bool binSearch(const std::vector<T>& v, int begin, int end, T val)
{
	
	if(begin > end)
		return false;
	int middle = (end+begin)/2;

	if(v[middle] == val)
		return true;
	else if(v[middle] > val)
		return binSearch(v, begin, middle-1, val);
	else
		return binSearch(v, middle+1, end, val);
}
int main()
{
	std::vector<int> v{1,2,3,4,5};
	std::cout<<std::boolalpha<<binSearch(v, 0, v.size()-1,5)<<" "<<
		   binSearch(v, 0, v.size()-1, 6)<<std::endl;
}
