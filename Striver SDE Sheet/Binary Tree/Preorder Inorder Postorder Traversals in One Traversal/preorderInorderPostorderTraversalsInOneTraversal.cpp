// Preorder Inorder Postorder Traversals in One Traversal

#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

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
    };


************************************************************/

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    stack<pair<BinaryTreeNode<int>*, int>> s;
    s.push({root, 1});
    vector<vector<int>> res;
    if(root==NULL)
        return res;

    vector<int> preorder;
    vector<int> inorder;
    vector<int> postorder;
    while(!s.empty())
    {
        auto curr = s.top();
        s.pop();

        // this is part of preorder
        // increment 1 to 2 
        // push the left side of the tree
        if(curr.second == 1)
        {
            preorder.push_back(curr.first->data);
            curr.second++;
            s.push(curr);
            if(curr.first->left != NULL)
            {
                s.push({curr.first->left, 1});
            }
        }
        
        // this is a part of inorder
        // increment 2 to 3 
        // push right 
        else if(curr.second == 2)
        {
            inorder.push_back(curr.first->data);
            curr.second++;
            s.push(curr);
            if(curr.first->right != NULL)
            {
                s.push({curr.first->right, 1});
            }
        }

        // this is a part of postorder
        // don't push it back again 
        else
        {
            postorder.push_back(curr.first->data);
        }
    }

    res.push_back(inorder);
    res.push_back(preorder);
    res.push_back(postorder);

    return res;
}