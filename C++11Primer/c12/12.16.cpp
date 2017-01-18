#include<memory>
int main()
{
	std::unique_ptr<int> p(new int(100));
	std::unique_ptr<int> c = p;

	std::unique_ptr<int> q(p);
	return 0;
}
