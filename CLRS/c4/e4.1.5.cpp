#include<iostream>
#include<vector>
#include<limits.h>
int maxSubarrLinear(std::vector<int> a)
{
	int maxSum = INT_MIN, total = 0, i = 0;
	for(int j = 0; j<a.size(); j++) {
		if(a[j] > maxSum) {
			i = j;
			total = a[j];
			maxSum = a[j];
		} else {
			total += a[j];
			if(total > maxSum)
				maxSum = total;
		}
	}
	return maxSum;
}
int main()
{
	std::vector<int> v{3, -1, 4, 5, -12, 100, 5};
	std::cout<<maxSubarrLinear(v)<<std::endl;
	return 0;
}
