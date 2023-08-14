// Encode N-ary tree to binary tree

#include <bits/stdc++.h> 
/************************************************************
    Binary tree node class for reference:

    template <typename T>
    class BTreeNode {
        public:
        T val;
        BTreeNode < T > * left;
        BTreeNode < T > * right;

        BTreeNode(T val) {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

    Nary tree node class for reference:

    class NTreeNode {
        public:
        T val;
        vector < NTreeNode < T > * > child;

        NTreeNode(T val) {
            this -> val = val;
        }
    };

************************************************************/

BTreeNode < int > * encode(NTreeNode < int > * root) {
    if(!root)
        return NULL;

    BTreeNode <int>* binaryRoot = new BTreeNode<int>(root->val);

    if(root->child.size()>0)
    {
        binaryRoot->left = encode(root->child[0]);
    }

    BTreeNode<int>* currentBinary = binaryRoot->left;
    for(int i=1;i<root->child.size();i++)
    {
        currentBinary->right = encode(root->child[i]);
        currentBinary = currentBinary->right;
    }

    return binaryRoot;
}

NTreeNode < int > * decode(BTreeNode < int > * binaryRoot) {
    if(!binaryRoot)
        return NULL;

    NTreeNode<int>* naryTree = new NTreeNode<int>(binaryRoot->val);
    BTreeNode<int>* currentBinary = binaryRoot->left;
    while(currentBinary)
    {
        naryTree->child.push_back(decode(currentBinary));
        currentBinary = currentBinary->right;
    }

    return naryTree;
} 