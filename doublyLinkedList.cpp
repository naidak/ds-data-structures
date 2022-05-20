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

void InsertAtTail(int x)
{
	Node* temp = new Node();
	Node* temp1 = head;
	temp->data = x;
	temp->next = nullptr;
	temp->prev = nullptr;
	if (head == nullptr)
	{
		head = temp;
		return;
	}

	while (temp1->next!=nullptr)
		temp1 = temp1->next;
	
	temp1->next = temp;
	temp->prev = temp1;
	
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
	{
		node = node->next;
	}

	while (node != nullptr)
	{
		cout << node->data<<" ";
		node = node->prev;
	}
}

int main() {
	InsertAtTail(1);
	InsertAtHead(4);
	InsertAtTail(7);
	InsertAtHead(8);
	InsertAtHead(9);
	InsertAtTail(3);

	print(head); //9 8 4 1 7 3
	cout << endl; 
	reversePrint(head); //3 7 1 4 8 9

	system("pause>0");
	return 0;
}
