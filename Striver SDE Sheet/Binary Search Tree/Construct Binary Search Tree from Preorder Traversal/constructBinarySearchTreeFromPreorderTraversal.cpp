// Construct Binary Search Tree from Preorder Traversal

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
    /*
        Time complexity:0(N)
        Space complexity:0(N
    */
    TreeNode* helper(vector<int>& preorder, int &index, int mini, int maxi)
    {
        if(index >= preorder.size())
        {
            return NULL;
        }
        if(preorder[index] < mini || preorder[index] > maxi)
        {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[index++]);
        root->left = helper(preorder, index, mini, root->val);
        root->right = helper(preorder, index, root->val, maxi);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        int mini = INT_MIN;
        int maxi = INT_MAX;
        return helper(preorder, index, mini, maxi);
    }
};