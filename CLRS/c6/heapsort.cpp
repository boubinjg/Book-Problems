#include<vector>
#include<iostream>
struct heap{
	size_t size;
	std::vector<int> heap;
};
void print(std::vector<int> v) {
	for(auto i : v)
		std::cout<<i<<" ";
	std::cout<<std::endl;
}
void maxheapify(heap& h, size_t i)
{
	size_t left = i*2+1, right = i*2+2;
	size_t max;
	if(left < h.size && h.heap[left] > h.heap[i])
		max = left;
	else
		max = i;
	if(right < h.size && h.heap[right] > h.heap[max])
		max = right;

	if(max != i) {
		std::swap(h.heap[max], h.heap[i]);
		maxheapify(h, max);
	}
}	
void makeHeap(heap& h)
{
	for(int i = h.size/2; i>=0; i--) {
		maxheapify(h, i);
	}
}	
void heapsort(heap& h)
{
	for(int i = h.size-1; i>0; i--) {
		std::swap(h.heap[i], h.heap[0]);
		h.size--;
		maxheapify(h, 0);
	}
}
int main()
{
	std::vector<int> v{0,1,7,8,9,2,3,5,10,4,6};
	print(v);
	heap h;
	h.size = v.size();
	h.heap = v;
	makeHeap(h);
	print(h.heap);
	heapsort(h);
	print(h.heap);

	return 0;
}
