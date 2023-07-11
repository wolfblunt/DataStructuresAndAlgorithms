// Predecessor and Successor

#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/
int findSuccessor(BinaryTreeNode<int>* root, int key)
{
    BinaryTreeNode<int> *ans = NULL;
    while(root)
    {
        if(key >= root->data)
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
    
int findPredecessor(BinaryTreeNode<int>* root, int key)
{
    BinaryTreeNode<int> *ans = NULL;
    while(root)
    {
        if(key <= root->data)
        {
            root = root->left;
        }
        else
        {
            ans = root;
            root = root->right;
        }
    }
    return ans!=NULL ? ans->data:-1;
}

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    pair<int, int> ans;
    int pre = findPredecessor(root, key);
    int suc = findSuccessor(root, key);
    ans = {pre, suc};
    return ans;
}
