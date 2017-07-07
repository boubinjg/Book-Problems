#include<iostream>
struct node {
	node* right, *left;
	int val;
};
void printTree(node* root){
	if(root != nullptr){
		std::cout<<root->val<<std::endl;
		printTree(root->right);
		printTree(root->left);
	}
}
int main()
{
	node* a = new node;
	a->val = 0;
	node* b = new node;
	node* c = new node;
	a->left = b;
	a->right = c;
	b->val = 2;
	c->val = 3;

	printTree(a);
	return 0;
}
