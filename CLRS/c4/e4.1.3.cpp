#include<iostream>
#include<vector>
#include<limits.h>
struct subArr{
        int min, max, sum;
};
subArr findMaxSubBrute(const std::vector<int>& a, int low, int high){
        int maxSum = INT_MIN;
	int left, right;
        for(int i = low; i<=high; i++) {
                int sum = 0;
                for(int j = i; j<a.size(); j++) {
                        sum += a[j];
                        if(sum > maxSum) {
                                maxSum = sum;
				left = i;
				right = j;
			}
                }
        }
        return {left, right, maxSum};
}
void print(const std::vector<int>& v)
{
        for(auto i : v)
                std::cout<<i<<" ";
        std::cout<<std::endl;
}
subArr findMaxCrossingSubarray(const std::vector<int>& a, int low, int mid, int high)
{
        int leftSum = INT_MIN, maxLeft = mid, sum = 0;
        for(int i = mid; i>=low; i--) {
                sum += a[i];
                if(sum > leftSum) {
                        maxLeft = i;
                        leftSum = sum;
                }
        }
        int rightSum = INT_MIN, maxRight = mid+1;
        sum = 0;
        for(int i = mid+1; i<=high; i++) {
                sum += a[i];
                if(sum > rightSum) {
                        maxRight = i;
                        rightSum = sum;
                }
        }
        return {maxLeft, maxRight, leftSum + rightSum};
}
subArr findMaxSubarray(const std::vector<int>& a, int low, int high)
{
        if(high-low < 8)
                return findMaxSubBrute(a, low, high);
        int mid = (low+high)/2;
        subArr left = findMaxSubarray(a, low, mid);
        subArr right = findMaxSubarray(a, mid+1, high);
        subArr maxCross = findMaxCrossingSubarray(a, low, mid, high);
        if(left.sum >= right.sum && left.sum >= maxCross.sum)
                return left;
        else if(right.sum >= left.sum && right.sum >= maxCross.sum)
                return right;
        else
                return maxCross;
}
int main()
{
        std::vector<int> v{100, -4, 2, -5, 10, -11, 4};
        //on my machine, bruteforce outperforms normal at size 7.
	subArr i = findMaxSubarray(v, 0, 7);
        std::cout<<"The value of the max subarray for: "<<std::endl;
        print(v);
        std::cout<<"is "<<i.sum<<" Between "<<i.min<<" and "<<i.max<<std::endl;
	return 0;
}	

