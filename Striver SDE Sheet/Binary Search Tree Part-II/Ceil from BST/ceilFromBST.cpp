// Ceil from BST

#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/
int findSuccessor(BinaryTreeNode<int> * root, int x)
{
    BinaryTreeNode<int> *ans = NULL;
    while(root)
    {
        if(x > root->data)
        {
            root = root->right;
        }
        else
        {
            ans = root;
            root = root->left;
        }
    }
    return ans!=NULL ? ans->data:-1;
}

int findCeil(BinaryTreeNode<int> *node, int x){
    int suc = findSuccessor(node, x);
    return suc;
}