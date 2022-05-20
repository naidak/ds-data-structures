#include <iostream>
using namespace std;

template <class T>
class Node {
public:
	T data;
	Node* next;
	Node* prev;
};

Node <int> *head;

template <class T>
void InsertAtHead(T x)
{
	Node<T> * temp = new Node<T>();
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

template <class T>
void InsertAtTail(T x)
{
	Node<T> * temp = new Node<T>();
	Node<T> * temp1 = head;
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

template <class T>
void print(Node<T> * node)
{
	while (node!=nullptr)
	{
		cout << node->data<<" ";
		node = node->next;
	}
}
template <class T>
void reversePrint(Node<T> * node)
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
