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
void partition(std::vector<int>& v, int part)
{
	
}
int nselect(std::vector<int>& v, int i)
{
	std::vector<std::vector<int>> batch;
	for(int i = 0; i<v.size(); i+=5) {
		std::vector<int> row;
		for(int j = 0; j<5 && i+j<v.size(); j++)
			row.push_back(v[i+j]);
		batch.push_back(row);
	}
	std::cout<<"Constructed Batches:"<<std::endl;
	for(auto i : batch)
		print(i);
	
	for(int i = 0; i<batch.size(); i++)
		std::sort(batch[i].begin(), batch[i].end());
	std::cout<<"Sorted Batches:"<<std::endl;
	for(auto i : batch)
		print(i);
	
	std::vector<int> meds;
	for(auto i : batch)
		meds.push_back(i[i.size()/2]);
	std::cout<<"Medians:"<<std::endl;
	for(auto i : meds)
		std::cout<<i<<std::endl;
	
	
	
}
int main()
{
	std::random_device rnd;
	std::mt19937 mersene_engine(rnd());
	std::uniform_int_distribution<int> dist(INT_MIN,INT_MAX);
	auto gen = std::bind(dist, mersene_engine);

	std::vector<int> v(15);
	std::generate(begin(v), end(v), gen);
	print(v);
	
	nselect(v, 4);

	return 0;
}
