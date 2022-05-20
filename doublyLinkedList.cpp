#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
	Node* prev;
};

Node* head;

void InsertAtHead(int x)
{
	Node* temp = new Node();
	temp->data = x;
	temp->prev = nullptr;
	temp->next = nullptr;
	if (head == nullptr)
	{
		head = temp; return;
	}
	head->prev = temp;
	temp->next = head;
	head = temp;
}

void print(Node * node)
{
	while (node!=nullptr)
	{
		cout << node->data<<" ";
		node = node->next;
	}
}

void reversePrint(Node* node)
{
	while (node->next != nullptr)
		node = node->next;

	while (node != nullptr)
	{
		cout << node->data<<" ";
		node = node->prev;
	}
}

int main() {
	InsertAtHead(1);
	InsertAtHead(4);
	InsertAtHead(7);

	print(head);
	cout << endl;
	reversePrint(head);

	system("pause>0");
	return 0;
}
