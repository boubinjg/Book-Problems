#include<iostream>
#include<stack> 

struct node{
	node* left;
	node* right;
	node* parent;
	int val;
	bool printed;
};
void preorder(node* root){
	if(root != nullptr) {
		std::cout<<root->val<<std::endl;
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(node* root){
	if(root != nullptr) {
		postorder(root->left);
		postorder(root->right);
		std::cout<<root->val<<std::endl;
	}
}
void iterativeInorder(node* root){
	std::stack<node*> q;
	q.push(root);
	while(!q.empty()){
		node* cur = q.top();
		q.pop();
		if(cur->right != nullptr && !cur->right->printed)
			q.push(cur->right);
		if(cur->left != nullptr && !cur->left->printed){
			q.push(cur);
			q.push(cur->left);
		}
		else if(!cur->printed){
			std::cout<<cur->val<<std::endl;
			cur->printed = true;
		}
	}	
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

	iterativeInorder(root);
	std::cout<<std::endl;
	postorder(root);
	std::cout<<std::endl;
	preorder(root);
	std::cout<<std::endl;

	return 0;
}
