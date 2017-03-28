/*
A)
Inversions in A <2,3,8,6,1>
A[1],A[5]
A[2],A[5]
A[3],A[4]
A[3],A[5]
A[4],A[5]

B)
The array with the most inversions is an array of values sorted in descending order.
This value will have inversions equal to n(n+1)/2

C) Each inversion is another execution of the internal while loop in insertion sort.
   Insertion sort executes n + (number of inversions) times for a given input sequence.
*/
#include<vector>
#include<iostream>
int totalInversions = 0;
template <typename T>
std::vector<T> merge(std::vector<T> l, std::vector<T> r)
{
        int lc = 0, rc = 0;
        std::vector<T> ret;
        while(lc < l.size() && rc < r.size())
        {
                if(l[lc] < r[rc]) {
                        ret.push_back(l[lc]);
                        ++lc;
                } else {
                        ret.push_back(r[rc]);
                        ++rc;
			totalInversions += l.size()-lc;
                }
        }
        while(lc < l.size()) {
                ret.push_back(l[lc]);
                ++lc;
        }
        while(rc < r.size()){
                ret.push_back(r[rc]);
                ++rc;
        }
        return ret;
}
template <typename T>
std::vector<T> countInv(std::vector<T> v)
{
        //std::cout<<v.size()<<std::endl;
        if(v.size() < 2)
                return v;
        std::vector<T> left(v.begin(), v.begin()+v.size()/2);
        std::vector<T> right(v.begin()+v.size()/2, v.end());
        left = countInv(left);
        right = countInv(right);
        left = merge(left, right);
        return left;
}
int main()
{
        std::vector<int> v{5,4,3,2,1};
        countInv(v);
	std::cout<<totalInversions<<std::endl;
}

