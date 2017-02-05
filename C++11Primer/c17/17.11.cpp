#include<iostream>
#include<bitset>
#include<algorithm>
struct quiz{
	std::bitset<10> b, answers;
	void add(unsigned pos, bool bv) {
		b.set(pos, bv);
	}
	int grade() {
		std::bitset<10> ret = b^answers;
		return ret.count();
	}
	void setAnswers(std::string s)
	{
		answers = std::bitset<10>(s);
	}
};
int main()
{
	quiz q;
	q.setAnswers("0101010101");
	q.add(1,1);
	q.add(3,1);
	q.add(5,1);
	q.add(7,1);
	std::cout<<q.grade()<<std::endl;
	return 0;
}
