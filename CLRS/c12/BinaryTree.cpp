#include "BinaryTree.h"
template class BinaryTree<int>;

template <typename T>
void BinaryTree<T>::remove(T val){
	node<T>* n = find(val);
	if(n->right == nullptr && n->left == nullptr){
		node<T>* p = n->parent;
		if(p->left == n) {
			delete p->left;
			n = nullptr;
			p->left = nullptr;
		}
		else if(p->right == n) { 
			delete p->right;
			n = nullptr;
			p->right == nullptr;
		}
	}
	else if(n->right == nullptr && n->left != nullptr){
		node<T>* l = n->left, *p = n->parent;
		if(p->left == n){
			delete p->left;
			n = nullptr;
			p->left = l;
		}
		else{
			delete p->right;
			n = nullptr;
			p->right = l;

		}
	}
	else if(n->left == nullptr && n->right != nullptr){
		node<T>* r = n->right, *p = n->parent;
		if(p->left == n){
			delete p->left;
			n = nullptr;
			p->left = r;
		}
		else{
			delete p->right;
			n = nullptr;
			p->right = r;

		}	
	}
	//if you get bored, in the deletion if it has 2 children.
}
template <typename T>
node<T>* BinaryTree<T>::find(T val){
	return find(val, root);		
}
template <typename T>
node<T>* BinaryTree<T>::find(T val, node<T>* n){
	if(n == nullptr || n->val == val){
		return n;
	}
	else if(n->val >= val){
		find(val, n->left);
	}
	else{
		find(val, n->right);
	}
}
template <typename T>
void BinaryTree<T>::insert(node<T>* r, node<T>* p, node<T>* in){
	if(r == nullptr){
		in->parent = p;
		if(p != nullptr){
			if(p->val >= in->val)
				p->left = in;
			else
				p->right = in;
		}
		return;
	}
	else if(r->val >= in->val){
		insert(r->left, r, in);
	}
	else if(r->val < in->val){
		insert(r->right, r, in);
	}
}
template <typename T>
void BinaryTree<T>::insert(T in){
	
	node<T>* n = new node<T>;
	n->val = in;
	if(root == nullptr) {
		root = n;
	}
	else
		insert(root, nullptr, n);
}
template <typename T>
T BinaryTree<T>::treeMinimum(){
	if(root->left != nullptr){
		return treeMinimum(root->left);
	}
	return root->val;
}
template <typename T>
T BinaryTree<T>::treeMinimum(node<T>* r){
	if(r->left != nullptr){
		return treeMinimum(r->left);
	}
	return r->val;
}
template <typename T>
T BinaryTree<T>::treeMaximum(){
	if(root->right != nullptr){
		return treeMaximum(root->right);
	}
	return root->val;
}
template <typename T>
T BinaryTree<T>::treeMaximum(node<T>* r){
	if(r->right != nullptr){
		return treeMaximum(r->right);
	}
	return r->val;
}
template <typename T>
T BinaryTree<T>::treeSuccessor(node<T>* n){
	if(root->right != nullptr){
		return treeMaximum(root->right);
	}
	node<T>* y = root->parent;
	while(y != nullptr && root == y->right) {
		root = y;
		y = y->parent;
	}
	return y->val;
}
template <typename T>
T BinaryTree<T>::treePredecessor(node<T>* n){
	if(root->left != nullptr){
		return treeMaximum(root->left);
	}
	node<T>* y = root->parent;
	while(y != nullptr && root == y->left) {
		root = y;
		y = y->parent;
	}
	return y->val;
}
template <typename T>
void BinaryTree<T>::preorder(node<T>* root){
        if(root != nullptr) {
                std::cout<<root->val<<std::endl;
                preorder(root->left);
                preorder(root->right);
        }
}
template <typename T>
void BinaryTree<T>::postorder(node<T>* root){
        if(root != nullptr) {
                postorder(root->left);
                postorder(root->right);
                std::cout<<root->val<<std::endl;
        }
}
template <typename T>
void BinaryTree<T>::inorder(node<T>* r){
	if(r != nullptr) {
		inorder(r->left);
		std::cout<<r->val<<std::endl;
		inorder(r->right);
	}
}
