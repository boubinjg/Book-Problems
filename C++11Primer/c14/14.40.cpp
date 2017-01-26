#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
class print{
public:
	void operator()(const std::string s) {std::cout<<s<<std::endl;}
};
class bigTest{
public:
	bigTest(int size) : sz(size) {}
	bool operator()(const std::string a, const std::string b) const {
		return a.size() < b.size();
	}
	bool operator()(const std::string a) const {
		return a.size() >= sz;
	}
private:
	int sz;
};
void biggies(std::vector<std::string> &words,
	    std::vector<std::string>::size_type sz)
{
	bigTest b(sz);
	print p;
	std::stable_sort(words.begin(), words.end(), b);
	auto wc = std::find_if(words.begin(), words.end(), b);
	auto count = words.end() - wc;
	std::cout<<count<<std::endl;
	
	std::for_each(wc, words.end(), p);
	std::cout<<std::endl;
}
int main()
{
	std::vector<std::string> v{"asdfasdf", "f", "ffffff"};
	biggies(v, 3);
	return 0;
}
