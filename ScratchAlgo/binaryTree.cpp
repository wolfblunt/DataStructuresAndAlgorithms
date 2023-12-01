#include<bits/stdc++.h>
using namespace std;

class bstNode
{
public:
	bstNode* left;
	bstNode* right;
	int data;

	bstNode(int x)
	{
		data = x;
		left = NULL;
		right = NULL;
	}
};


bstNode* bstInsert(bstNode* root, int item)
{
	if(!root)
	{
		bstNode* temp = new bstNode(item);
		return temp;
	}

	if(item > root->data)
	{
		root->right = bstInsert(root->right, item);
	}
	else if(item < root->data)
	{
		root->left = bstInsert(root->left, item);
	}
	return root;
}

void printBST(bstNode* root)
{
	if(!root)
	{
		return;
	}
	printBST(root->left);
	cout<<root->data<<" ";
	printBST(root->right);
}


bstNode* minValueNode(bstNode *node) {
  bstNode *current = node;

  // Find the leftmost leaf
  while (current && current->left != NULL)
    current = current->left;

  return current;
}

bstNode* deleteNode(bstNode* root, int item)
{
	if(!root)
	{
		return root;
	}

	if(item < root->data)
	{
		root->left = deleteNode(root->left, item);
	}
	else if(item > root->data)
	{
		root->right = deleteNode(root->right, item);
	}
	else
	{
		if(!root->left)
		{
			bstNode* temp = root->right;
			free(root);
			return temp;
		}
		else if(!root->right)
		{
			bstNode* temp = root->left;
			free(root);
			return temp;
		}

		bstNode* temp = minValueNode(root->right);
		root->data = temp->data;
		root->right = deleteNode(root->right, temp->data);
	}

	return root;
}

int main()
{
	bstNode* root = NULL;
	root = bstInsert(root, 20);
    root = bstInsert(root, 10);
    root = bstInsert(root, 5);
    root = bstInsert(root, 15);
    root = bstInsert(root, 40);
    root = bstInsert(root, 45);
    root = bstInsert(root, 30);

    printBST(root);
    cout<<endl;
    root = deleteNode(root, 20);
    printBST(root);
	return 0;
}