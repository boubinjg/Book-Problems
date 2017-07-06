#include<iostream>
#include<vector>
template<typename T>
class queue{
public:
	queue(size_t s) : size(s){
		q = std::vector<T>(size);
		head = 0;
		tail = 0;
		capacity = 0;
	}
	void enqueue(T in){
		if(++capacity > size) {
			std::cerr<<"overflow"<<std::endl;
			capacity = size;
		}
		else {
			q[tail] = in;
			tail = (tail+1) % size;
			std::cout<<tail<<std::endl;
		}
	}
	T dequeue(){
		if(!capacity) {
			std::cerr<<"underflow"<<std::endl;
			capacity = 0;
		}
		else{
			T ret = q[head];
			head = (head+1)%size;
			--capacity;
			return ret;
		}
		return 0;
	}

private:
	std::vector<T> q;
	size_t head, tail, size, capacity;
};
int main()
{
	queue<int> q(3);
	q.dequeue();
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	std::cout<<q.dequeue()<<std::endl;
	std::cout<<q.dequeue()<<std::endl;
	std::cout<<q.dequeue()<<std::endl;
	return 0;
}
