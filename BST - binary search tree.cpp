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

	system("pause>0");
	return 0;
}
