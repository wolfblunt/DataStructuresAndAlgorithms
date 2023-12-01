#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node* next;

	Node(int x)
	{
		data = x;
		next = NULL;
	}
};


class LinkedList
{
	Node* head;
public:
	LinkedList()
	{
		head = NULL;
	}

	void insertNode(int);

	void printList();

	void deleteNode(int);
};

void LinkedList::insertNode(int data)
{
	Node* newNode = new Node(data);
	if(head == NULL)
	{
		head = newNode;
		return;
	}

	Node* temp = head;
	while(temp->next)
	{
		temp = temp->next;
	}
	temp->next = newNode;
}

void LinkedList::printList()
{
	Node* temp = head;
	if(head == NULL)
	{
		cout<<"Empty list"<<endl;
		return;
	}

	while(temp)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

void LinkedList::deleteNode(int dnode)
{
	Node* temp1 = head;
	Node* temp2 = NULL;

	if(!head)
	{
		cout<<"List is Empty"<<endl;
		return;
	}

	while(temp1 && temp1->data != dnode)
	{
		temp2 = temp1;
		temp1 = temp1->next;
	}

	temp2->next = temp1->next;
}

int main()
{
	LinkedList list;
	list.insertNode(1);
	list.insertNode(10);
	list.insertNode(2);
	list.insertNode(3);
	list.insertNode(4);
	list.printList();

	list.deleteNode(10);
	list.printList();
	return 0;
}