#include<iostream>
#include<stack> 

struct node{
	node* left;
	node* right;
	node* parent;
	int val;
	bool printed;
};
int treeMinimum(node* root){
	if(root->left != nullptr){
		return treeMinimum(root->left);
	}
	return root->val;
}
int treeMaximum(node* root){
	if(root->right != nullptr){
		return treeMaximum(root->right);
	}
	return root->val;
}
int treeSuccessor(node* root){
	if(root->right != nullptr){
		return treeMaximum(root->right);
	}
	node* y = root->parent;
	while(y != nullptr && root == y->right) {
		root = y;
		y = y->parent;
	}
	return y->val;
}
int treePredecessor(node* root){
	if(root->left != nullptr){
		return treeMaximum(root->left);
	}
	node* y = root->parent;
	while(y != nullptr && root == y->left) {
		root = y;
		y = y->parent;
	}
	return y->val;
}
int main()
{
	node* root = new node;
	node* left = new node;
	node* right = new node;
	node* leftright = new node;
	node* leftleft = new node;
	node* rightleft = new node;
	node* rightright = new node;

	root-> val = 5;
	left->val = 3;
	leftleft->val = 0;
	leftright->val = 4;
	right->val = 10;
	rightleft->val = 7;
	rightright->val = 12;

	root->left = left;
	root->right = right;
	left->left = leftleft;
	left->right = leftright;
	right->left = rightleft;
	right->right = rightright;

	left->parent = root;
	right->parent = root;
	leftleft->parent = left;
	leftright->parent = left;
	rightright->parent = right;
	rightleft->parent = left;


	node* newnode;
	newnode->val = -5;
	insert(root, nullptr, newnode);
	iterativeInorder(root); 
	return 0;
}
