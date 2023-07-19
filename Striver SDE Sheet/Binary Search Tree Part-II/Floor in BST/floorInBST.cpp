// Floor in BST

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
int findPredecessor(TreeNode<int> * root, int x)
{
    TreeNode<int> *ans = NULL;
    while(root)
    {
        if(x < root->val)
        {
            root = root->left;
        }
        else
        {
            ans = root;
            root = root->right;
        }
    }
    return ans!=NULL ? ans->val:-1;
}

int floorInBST(TreeNode<int> * root, int x)
{
    int pre = findPredecessor(root, x);
    return pre;
}