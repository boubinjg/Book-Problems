#include<string>
class TreeNode {
private:
	std::string value;	
	int count;
	TreeNode *left;
	TreeNode *right;
	int *use;

public:
	TreeNode() : use(new int(0)) {}
	TreeNode(TreeNode& rhs);
	TreeNode& operator=(TreeNode& rhs);
	~TreeNode();
};
class BinStrTree {
private:
	TreeNode* root;
	int *use;
public:
	BinStrTree() : use(new int(0)) {}
	BinStrTree(BinStrTree& rhs);
	BinStrTree& operator=(BinStrTree& rhs);
	~BinStrTree();
};

TreeNode::TreeNode(TreeNode& rhs) : count(rhs.count), value(rhs.value)
{
	left = rhs.left;
	right = rhs.right;
	use = rhs.use;
	*use++;
}
TreeNode& TreeNode::operator=(TreeNode& rhs)
{
	if(!(--*use)) {
		delete left;
		delete right;
		delete use;	
	}
	
	left = rhs.left;
	right = rhs.right;
	count = rhs.count;
	value = rhs.value;	

	return *this;
}
TreeNode::~TreeNode()
{
	if(!(--*use)) {
		delete left;
		delete right;
		delete use;
	}
}
BinStrTree::BinStrTree(BinStrTree& rhs)
{
	use = rhs.use;
	root = rhs.root;
	*use++;
}
BinStrTree& BinStrTree::operator=(BinStrTree& rhs) 
{
	if(!(--*use)) {
		delete root;
		delete use;
	}
	root = rhs.root;
	use = rhs.use;
	++*use;
	return *this;
}
BinStrTree::~BinStrTree()
{
	if(!(--*use)) {
		delete use;
		delete root;
	}
}

