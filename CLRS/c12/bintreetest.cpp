#include "BinaryTree.h"
#include "BinaryTree.cpp"
int main(){
	BinaryTree<int> b;
	std::cout<<"Inserting"<<std::endl;
	b.insert(5);
	b.insert(10);
	b.insert(0);
	b.insert(3);
	std::cout<<"in"<<std::endl;
	
	b.inorder();
	
	b.remove(0);
	std::cout<<std::endl;
	
	b.inorder();

	return 0;
}
