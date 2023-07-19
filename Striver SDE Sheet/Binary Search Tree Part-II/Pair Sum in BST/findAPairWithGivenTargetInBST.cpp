// Find a pair with given target in BST

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
    void helper(TreeNode* root, vector<int>& inorder)
    {
        if(!root)
        {
            return;
        }
        helper(root->left, inorder);
        inorder.push_back(root->val);
        helper(root->right, inorder);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        helper(root, inorder);

        for(int i=0;i<inorder.size();i++)
        {
            int s = k - inorder[i];
            int low = i+1;
            int high = inorder.size()-1;
            while(low<=high)
            {
                int mid = low + (high-low)/2;
                if(inorder[mid] == s)
                {
                    return true;
                }
                else if(inorder[mid] > s)
                {
                    high = mid-1;
                }
                else
                {
                    low = mid + 1;
                }
            }
        }
        return false;
    }
};