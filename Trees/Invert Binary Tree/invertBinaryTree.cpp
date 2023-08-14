// Invert Binary Tree

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
    TreeNode* invertTree(TreeNode* root) {
       if(root == NULL)
       {
            return root;
        }
        // Call the function recursively for the left subtree...
        invertTree(root->left);
        // Call the function recursively for the right subtree...
        invertTree(root->right);
        // Swapping process...
        TreeNode* curr = root->left;
        root->left = root->right;
        root->right = curr;
        return root;   
    }
};