// Construct Binary Tree from Preorder and Postorder Traversal - O(n)

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
    int preIndex = 0;
    int postIndex = 0;
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        TreeNode* curr = new TreeNode(preorder[preIndex]);
        preIndex++;

        if(curr->val != postorder[postIndex])
        {
            curr->left = constructFromPrePost(preorder, postorder);
        }
        if(curr->val != postorder[postIndex])
        {
            curr->right = constructFromPrePost(preorder, postorder);
        }

        postIndex++;
        return curr;
    }
};