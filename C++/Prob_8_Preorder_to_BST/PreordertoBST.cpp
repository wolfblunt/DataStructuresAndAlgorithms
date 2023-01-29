// Preorder to BST
#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* left, *right;
	Node(int val)
	{
		data = val;
		left = NULL;
		right = NULL;
	}
};


Node* constructBST(int preOrder[], int* preOrderIdx, int key, int min, int max, int size)
{
	if(*preOrderIdx>=size)
	{
		return NULL;
	}

	Node* root = NULL;

	if(key<max && key>min)
	{
		root = new Node(key);
		*preOrderIdx = *preOrderIdx + 1;

		if(*preOrderIdx<size)
		{
			root->left = constructBST(preOrder, preOrderIdx, preOrder[*preOrderIdx], min, key, size);
		}

		if(*preOrderIdx<size)
		{
			root->right = constructBST(preOrder, preOrderIdx, preOrder[*preOrderIdx], key, max, size);
		}
	}

	return root;
}


void printpreOrder(Node* root)
{
	if(root == NULL)
	{
		return;
	}
	cout<<root->data<<" ";
	printpreOrder(root->left);
	printpreOrder(root->right);
}

void printpostOrder(Node* root)
{
	if(root == NULL)
	{
		return;
	}

	printpostOrder(root->left);
	printpostOrder(root->right);
	cout<<root->data<<" ";
}

void printinOrder(Node* root)
{
	if(root == NULL)
	{
		return;
	}

	printpostOrder(root->left);
	cout<<root->data<<" ";
	printpostOrder(root->right);
}


int main()
{
	int preOrder[] = {10,2,1,13,11};
	int size = 5;
	int preOrderIdx = 0;
	Node* root = constructBST(preOrder, &preOrderIdx, preOrder[0], INT_MIN, INT_MAX, size);
	cout<<"---------------Pre order Traversal------------\n";
	printpreOrder(root);
	cout<<"\n---------------Post order Traversal------------\n";
	printpostOrder(root);
	cout<<"\n---------------In order Traversal------------\n";
	printinOrder(root);
	return 0;
}