#ifndef _BINTREE_
#define _BINTREE_
#include<iostream>
#include<stack> 
template <typename T>
struct node{
	node<T>* left;
	node<T>* right;
	node<T>* parent;
	T val;
};

template <typename T>
class BinaryTree{
public:
	BinaryTree(){root = nullptr;};
	void insert(T in);
	void remove(T out);  
      
	T treeMinimum();
	T treeMaximum();
	T treeMinimum(node<T>* r);
	T treeMaximum(node<T>* r);	

        T treeSuccessor(node<T>* n);
	T treePredecessor(node<T>* n);
	
        void preorder(){preorder(root);};
        void postorder(){postorder(root);};
        void inorder(){inorder(root);};
private:
	void insert(node<T>* r, node<T>* p, node<T>* in);
	node<T>* find(T val, node<T>* n);
	node<T>* find(T val);
	void preorder(node<T>* n);
	void postorder(node<T>* n);
	void inorder(node<T>* r);
	node<T>* root;
};
#endif
