// Symmetric Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameLeftRight(TreeNode* leftTree, TreeNode* rightTree)
    {
        if(!leftTree && !rightTree)
            return true;
        
        if(!leftTree || !rightTree)
            return false;
        
        if(leftTree->val != rightTree->val)
            return false;
        
        return isSameLeftRight(leftTree->left ,rightTree->right) && isSameLeftRight(leftTree->right ,rightTree->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
        {
            return true;
        }
        return isSameLeftRight(root->left, root->right);
    }
};