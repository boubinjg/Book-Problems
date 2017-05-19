#include<iostream>
#include<algorithm>
#include<random>
#include<climits>
#include<functional>
void print(std::vector<int>& v)
{
	for(auto i : v)
		std::cout<<i<<" ";
	std::cout<<std::endl;
}
int partition(std::vector<int>& v, int beg, int end, int pval)
{
	int i = beg-1;
	for(int j = beg; j<end; ++j) {
		if(v[j] <= pval) {
			++i;
			std::swap(v[i],v[j]);
		}
	}
	
	return i;
}
int nselect(std::vector<int>& v, int beg, int end, int i)
{
	if(end-beg <= 5) {
		std::cout<<"returning from min"<<std::endl;
		std::sort(v.begin()+beg, v.begin()+end);
		print(v);
		int ret = v[beg+i];
		std::cout<<ret<<std::endl;
		return ret;
	}
	std::vector<int> meds;
	for(int i = beg; i<end; i+=5) {
		if(i+5 < end) {
			std::sort(v.begin()+i, v.begin()+i+5);	
			meds.push_back(v[i+2]);
		} else {
			std::sort(v.begin()+i, v.begin()+end);
			meds.push_back(v[i+(end-i)/2]);
		}
	}
	std::sort(meds.begin(), meds.end());
	std::cout<<"Medians"<<std::endl;
	print(meds);
	int medofmed = meds[(meds.size()-1)/2];
	std::cout<<"Median"<<medofmed<<std::endl;
	int p = partition(v, beg, end, medofmed);
	std::cout<<"P: "<<p<<std::endl;
	print(v);
	if(p == i) {
		std::cout<<"return medofmed"<<std::endl;
		return medofmed;
	}
	else if(i < p)
		nselect(v, beg, p+1, i);
	else
		nselect(v, p, end, i-p);
}
int main()
{
	/*std::random_device rnd;
	std::mt19937 mersene_engine(rnd());
	std::uniform_int_distribution<int> dist(INT_MIN,INT_MAX);
	auto gen = std::bind(dist, mersene_engine);

	std::vector<int> v(15);
	std::generate(begin(v), end(v), gen);
	print(v);*/
	
	std::vector<int> v = {1,2,3,4,5,6,7};//{1,5,4,2,3,0,9,7,8,6};
	int val = nselect(v,0,v.size(),4);
	std::cout<<val<<std::endl;
	//std::sort(v.begin(), v.end());
	//std::cout<<v[4]<<std::endl;
	//print(v);
	return 0;
}
