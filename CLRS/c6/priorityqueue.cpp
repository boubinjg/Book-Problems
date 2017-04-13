#include<vector>
#include<iostream>
#include<limits.h>
class Heap {
public:
	
	void maxheapify(size_t i)
	{
		size_t left = i*2+1, right = i*2+2;
		size_t max;
		if(left < size && heap[left] > heap[i])
			max = left;
		else
			max = i;
		if(right < size && heap[right] > heap[max])
			max = right;

		if(max != i) {
			std::swap(heap[max], heap[i]);
			maxheapify(max);
		}
	}	
	void makeHeap(Heap& h){
		for(int i = h.size/2; i>=0; i--) {
			maxheapify(i);
		}
	}
	Heap(std::vector<int> v){
		heap = v;
		size = v.size();
		makeHeap(*this);
	}
	void print() {
		for(auto i : heap)
			std::cout<<i<<" ";
		std::cout<<std::endl;
	}
	size_t size;
	std::vector<int> heap;
};	
class PriorityQueue {
public:
	PriorityQueue(Heap& h) : pq(h) {}
	int top() {
		return pq.heap[0];
	}
	int pop() {
		int ret = top();
		std::swap(pq.heap[0], pq.heap[pq.size]);
		--pq.size;
		pq.maxheapify(0);
		return ret;
	}
	void increaseKey(size_t i, int key) {
		if(key > pq.heap[i]) {
			pq.heap[i] = key;
			while(i > 0 && pq.heap[i/2] < pq.heap[i]) {
				std::swap(pq.heap[i], pq.heap[i/2]);
				i/= 2;
			}	
		}
	}
	void insert(int val) {
		++pq.size;
		pq.heap[pq.size] = INT_MIN;
		increaseKey(pq.size, val);
	}
private:
	Heap pq;
};
int main()
{
	std::vector<int> v{0,1,7,8,9,2,3,5,10,4,6};
	Heap h(v);
	h.print();
	PriorityQueue pq(h);
	std::cout<<pq.top()<<std::endl;
	std::cout<<pq.pop()<<std::endl;
	std::cout<<pq.top()<<std::endl;
	pq.insert(1000);
	std::cout<<pq.top()<<std::endl;
	return 0;
}
