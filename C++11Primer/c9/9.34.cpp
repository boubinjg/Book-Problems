#include<iostream>
#include<vector>
int main()
{
	std::vector<int> vi{1,2,3,4,5};
	auto iter = vi.begin();
	//we are always inserting infront of iter, and the incrementation is never reached because
	//it is outside the scope of the while loop
	while(iter != vi.end())
		if(*iter%2)
			iter = vi.insert(iter, *iter);
		++iter;
	return 0;
}
