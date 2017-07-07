#include<iostream>
struct node{
	node* next;
	int val;
};
struct list{
	node* head;
	list(){
		head = nullptr;
	}
	void push(int i){
		node* n = new node;
		n->val = i;
		if(head == nullptr){
			head = n;	
		} else {
			n->next = head;
			head = n;
		}
	}
	int pop(){
		int ret = head->val;
		node* n = head;
		head = n->next;
		delete n;
		return ret;	
	}
	void print(){
		node* n = head;
		while(n != nullptr){
			std::cout<<n->val<<std::endl;
			n = n->next;
		}
	}
	void reverse(){
		node *cur = head, *last = nullptr, *next = nullptr;
		while(cur->next != nullptr){
			next = cur->next;
			cur->next = last;
			last = cur;
			cur = next;
		}
		cur->next = last;
		head = cur;
	}
};
int main()
{
	list l;
	l.push(1);
	l.push(2);
	l.push(3);
	l.print();

	l.reverse();
	std::cout<<std::endl;	

	l.print();
	
	return 0;
}
