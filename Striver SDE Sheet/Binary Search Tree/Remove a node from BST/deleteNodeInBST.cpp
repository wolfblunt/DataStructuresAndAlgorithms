// Delete a Node in BST

#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
TreeNode<int> *inOrderSucc(TreeNode<int> *root)
{
    TreeNode<int> *curr = root;
    while(curr && curr->left!=NULL)
    {
        curr = curr->left;
    }
    return curr;
}

TreeNode<int> * removeNode(TreeNode<int> *root, int x)
{
    if(root)
    {
        if(x < root->val)
        {
            root->left = removeNode(root->left, x);
        }
        else if(x > root->val)
        {
            root->right = removeNode(root->right, x);
        }
        else
        {
            if(!root->left)
            {
                TreeNode<int> *temp = root->right;
                free(root);
                return temp;
            }
            else if(!root->right)
            {
                TreeNode<int> *temp = root->left;
                free(root);
                return temp;
            }

            // if both children are present
            TreeNode<int> *temp = inOrderSucc(root->right);
            root->val = temp->val;
            root->right = removeNode(root->right, temp->val);
        }
    }

}