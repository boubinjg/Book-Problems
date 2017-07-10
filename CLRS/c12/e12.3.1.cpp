#include<iostream>
#include<stack> 

struct node{
	node* left;
	node* right;
	node* parent;
	int val;
	bool printed;
};
void insert(node* root, node* p, node* in){
	if(root == nullptr){
		root = in;
		root->parent = p;
		if(p->val > root->val)
			p->left = root;
		else
			p->right = root;
	}
	if(root->val > in->val){
		insert(root->left, root, in);
	}
	if(root->val < in->val){
		insert(root->right, root, in);
	}
}
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

	node* newnode = new node;
        newnode->val = -5;
	node* newnode2 = new node;
	newnode2->val = 6;
	node* newnode3 = new node;
	newnode3->val = 15;
	std::cout<<"inserting"<<std::endl;
        insert(root, nullptr, newnode);
	insert(root, nullptr, newnode2);
	insert(root, nullptr, newnode3);
	std::cout<<"insert"<<std::endl;
        iterativeInorder(root);

	return 0;
}
