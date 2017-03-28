#include<iostream>
#include<vector>
template <typename T>
void print(std::vector<T> v)
{
	for(auto i : v)
		std::cout<<i<<" ";
	std::cout<<std::endl;
}
template <typename T>
std::vector<T> merge(std::vector<T> l, std::vector<T> r)
{
	int lc = 0, rc = 0;
	std::vector<T> ret;
	while(lc < l.size() && rc < r.size())
	{
		if(l[lc] < r[rc]) {
			ret.push_back(l[lc]);
			++lc;
		} else {
			ret.push_back(r[rc]);
			++rc;
		}	
	}
	while(lc < l.size()) {
		ret.push_back(l[lc]);
		++lc;
	}
	while(rc < r.size()){
		ret.push_back(r[rc]);
		++rc;
	}
	return ret;
}
template <typename T>
std::vector<T> sort(std::vector<T> v)
{
	//std::cout<<v.size()<<std::endl;
	if(v.size() < 2)
		return v;
	std::vector<T> left(v.begin(), v.begin()+v.size()/2);
	std::vector<T> right(v.begin()+v.size()/2, v.end());
	left = sort(left);
	right = sort(right);
	left = merge(left, right);
	return left;
}
int main()
{
	std::vector<int> v{5,4,3,2,1};
	print(v);
	v = sort(v);
	print(v);
}
