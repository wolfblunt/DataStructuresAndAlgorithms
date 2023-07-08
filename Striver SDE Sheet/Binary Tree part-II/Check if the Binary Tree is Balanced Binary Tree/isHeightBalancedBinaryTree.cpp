// Is Height Balanced Binary Tree

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
    int checkHeight(TreeNode* root, bool &isValid)
    {
        if(!isValid)
        {
            return 0;
        }
        if(!root)
        {
            return 0;
        }

        int lh = checkHeight(root->left, isValid);
        int rh = checkHeight(root->right, isValid);
        if(isValid && abs(lh-rh) > 1)
        {
            isValid = false;
            return 0;
        }
        return max(lh, rh)+1;
    }

    bool isBalanced(TreeNode* root) {
        bool isValid = true;
        checkHeight(root,isValid);
        return isValid;
    }
};