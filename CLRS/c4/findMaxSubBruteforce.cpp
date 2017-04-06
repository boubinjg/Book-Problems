#include<vector>
#include<iostream>
#include<limits.h>
int findMaxSubarray(const std::vector<int>& a){
	int maxSum = INT_MIN;	
	for(int i = 0; i<a.size(); i++) {
		int sum = 0;
		for(int j = i; j<a.size(); j++) {
			sum += a[j];
			if(sum > maxSum)
				maxSum = sum;
		}
	}
	return maxSum;
}
int main()
{
	std::vector<int> v{1,-3,2,4,5,-10,20};
	int i = findMaxSubarray(v);
	std::cout<<i<<std::endl;
	return 0;
}
