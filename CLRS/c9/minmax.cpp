#include<iostream>
#include<vector>
#include<utility>
#include<climits>
std::pair<int,int> minmax(std::vector<int> v)
{
	int min = INT_MAX, max = INT_MIN;
	int i = 0;
	if(v.size()%2) {
		min = max = v[i];
		++i;
	}
	for(; i<v.size(); i+=2) {
		if(v[i] < v[i+1]) {
			v[i] < min ? min = v[i] : min;
			v[i+1] > max ? max = v[i+1] : max;
		}
		else {
			v[i+1] < min ? min = v[i] : min;
			v[i] > max ? max = v[i+1] : max;
		}
	}
	return std::make_pair(min, max);
}
int main()
{
	std::vector<int> v{5,6,1,20,3,-20, 22, -1000};
	auto m = minmax(v);
	std::cout<<m.first<<" "<<m.second<<std::endl;
	return 0;
}
