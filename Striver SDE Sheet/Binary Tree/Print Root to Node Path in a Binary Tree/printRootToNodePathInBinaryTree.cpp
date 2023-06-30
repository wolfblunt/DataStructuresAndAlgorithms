// Print Root to Node Path in a Binary Tree

#include <bits/stdc++.h> 
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};
*/

bool inorder(TreeNode<int> *root, int x, vector<int> &result)
{
	if(!root)
		return false;
	
	result.push_back(root->data);
	if(root->data == x)
	{
		return true;
	}

	if(inorder(root->left, x, result) || inorder(root->right, x, result))
	{
		return true;
	}

	result.pop_back();
	return false;
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    vector<int> result;
	if(!root)
		return result;

	inorder(root, x, result);
	return result;
}
