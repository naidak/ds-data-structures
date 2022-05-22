#include <iostream>
using namespace std;

class BstNode {
public:
	int data;
	BstNode* left;
	BstNode* right;
};

BstNode* rootPtr; // storing address of a root node

BstNode* getNewNode(int data)
{
	BstNode* node = new BstNode();
	node->data = data;
	node->left = nullptr;
	node->right = nullptr;
	return node;
}

BstNode* Insert(BstNode* root, int data)
{
	if (root == nullptr)
		root = getNewNode(data);
	else if (data <= root->data)
		root->left = Insert(root->left, data);
	else
		root->right = Insert(root->right, data);
	return root;
}

bool Search(BstNode* root, int data)
{
	if (root == nullptr)return false;
	if (root->data == data)return true;
	if (data <= root->data)return Search(root->left, data);
	return Search(root->right, data);
}

int FindMin(BstNode* root) { //iterative solution
	if (root == nullptr)
	{
		cout << "Empty tree!";
		return -1;
	}
	while (root->left != nullptr) {
		root = root->left;
	} //going left as much asa possible
	return root->data;
}

//recursive solution for finding min element in BST
int FindMinRec(BstNode* root){
	if (root == nullptr)
	{
		cout << "Empty tree!";
		return -1;
	}
	if (root->left == nullptr)
		return root->data;
	return FindMinRec(root->left);
}

//iterative solution for finding max element in BST
int FindMax(BstNode* root)
{
	if (root == nullptr)
	{
		cout << "Tree is empty!"<<endl;
		return -1;
	}
	while (root->right != nullptr)
	{
		root = root->right;
	}

	return root->data;
}

//recursive solution 
int FindMaxRec(BstNode* root)
{
	if (root == nullptr)
	{
		cout << "Tree is empty!" << endl;
		return -1;
	}
	if (root->right == nullptr)
		return root->data;
	return FindMaxRec(root->right);
}

int main() {

	BstNode* root = nullptr;
	root=Insert(root, 15);
	root=Insert(root, 10);
	root=Insert(root, 20);
	root = Insert(root, 9);
	root = Insert(root, 23);
	root = Insert(root, 11);
	root = Insert(root, 19);

	int num;
	cout << "Enter the number that you're looking for: ";
	cin >> num;
	cout<<(Search(root, num) ? "Number founded" : "Number not found")<<endl;

	cout << "::::::::::::: Testing iterative solutions :::::::::::::" << endl;
	cout << "Min element: " << FindMin(root)<<endl;
	cout << "Max element: " << FindMax(root) << endl<<endl;

	cout << "::::::::::::: Testing recursive solutions :::::::::::::" << endl;
	cout << "Min element: " << FindMinRec(root) << endl;
	cout << "Max element: " << FindMaxRec(root) << endl << endl;


	system("pause>0");
	return 0;
}
